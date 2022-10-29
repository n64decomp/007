#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "pdtex.h"

/**
 * libpdtex - A library for reading and writing PD textures.
 *
 * Each PD texture, herein called a pdtex, can contain up to 7 images at
 * different levels of detail (LOD). Each image can use a different pixel format
 * and compression algorithm.
 *
 * PD uses a variety of compression algorithms on its texture data, and
 * sometimes more than one on the same image. Depending on the compression
 * algorithm and pixel format, the data can be rearranged to place all the alpha
 * values separate to the colour values for better compression. libpdtex
 * provides an abstraction for the compression and decompression of this data.
 *
 * The user of this library interacts with it by using pdtex and pdimage
 * structs. A pdtex is pretty much just an array of pdimages. A pdimage contains
 * the dimensions, format and pixel data in that format. pdimages also contain
 * a property for the compression algorithm, despite the pixel data having been
 * decompressed already. This is so the caller can request that a particular
 * compression method be used when writing a texture.
 */

int g_TexFormatNumChannels[] = { 4, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1 };
int g_TexFormatHas1BitAlpha[] = { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 };
int g_TexFormatChannelSizes[] = { 256, 32, 256, 32, 256, 16, 8, 256, 16, 256, 16, 256, 16 };
int g_TexFormatBitsPerPixel[] = { 32, 16, 24, 15, 16, 8, 4, 8, 4, 16, 16, 16, 16 };

int reader_read(FILE *fp, struct pd_tex *tex);
int writer_write(FILE *fp, struct pd_image *image);

struct pd_tex *pdtex_allocate(void)
{
	return calloc(1, sizeof(struct pd_tex));
}

void pdtex_free(struct pd_tex *tex)
{
	if (tex) {
		for (int i = 0; i < PDTEX_MAX_IMAGES; i++) {
			free(tex->images[i].pixels);
		}

		free(tex->palette);
		free(tex);
	}
}

void pdtex_flip(struct pd_tex *tex)
{
	uint8_t buffer[1000];
	int rowlen;

	for (int i = 0; i < PDTEX_MAX_IMAGES; i++) {
		if (tex->images[i].exists) {
			struct pd_image *image = &tex->images[i];
			int top = 0;
			int bottom = image->height - 1;

			if (image->format == PDFORMAT_RGBA16_CI8
					|| image->format == PDFORMAT_IA16_CI8
					|| image->format == PDFORMAT_RGBA16_CI4
					|| image->format == PDFORMAT_IA4_CI4) {
				// Paletted
				rowlen = image->width;
			} else if (image->format == PDFORMAT_I4) {
				// 4 bits in ROM, but at this point it's 8 bits
				rowlen = image->width;
			} else if (image->format == PDFORMAT_RGB15) {
				rowlen = 2 * image->width;
			} else {
				// Not paletted
				rowlen = g_TexFormatBitsPerPixel[image->format] * image->width / 8;
			}

			while (top < bottom) {
				memcpy(buffer, &image->pixels[top * rowlen], rowlen);
				memcpy(&image->pixels[top * rowlen], &image->pixels[bottom * rowlen], rowlen);
				memcpy(&image->pixels[bottom * rowlen], buffer, rowlen);

				top++;
				bottom--;
			}
		}
	}
}

int pdtex_read(struct pd_tex *tex, char *filename)
{
	FILE *fp = fopen(filename, "rb");

	if (!fp) {
		return errno;
	}

	if (!reader_read(fp, tex)) {
		return 1;
	}

	fclose(fp);

	return 0;
}

int pdtex_write(struct pd_image *image, char *filename)
{
	FILE *fp = fopen(filename, "wb");

	if (!fp) {
		return errno;
	}

	if (!writer_write(fp, image)) {
		return 1;
	}

	fclose(fp);

	return 0;
}

void pdtex_print(struct pd_tex *tex)
{
	int i;

	if (tex->palette) {
		printf("Palette: %d colours\n", tex->numcolours);

		for (i = 0; i < tex->numcolours; i++) {
			printf("0x%02x%02x\n", tex->palette[i * 2], tex->palette[i * 2 + 1]);
		}
	} else {
		printf("Palette: NULL\n");
	}

	struct pd_image *image = &tex->images[0];

	printf("Exists: %d\n", image->exists);
	printf("Format: %d\n", image->format);
	printf("Compression: %d\n", image->compression);
	printf("Width: %d\n", image->width);
	printf("Height: %d\n", image->height);

	if (image->pixels) {
		printf("Pixels:");

		for (i = 0; i < 0x100; i++) {
			if ((i % 0x10) == 0) {
				printf("\n");
			}

			printf("%02x ", image->pixels[i]);
		}
		printf("\n");
	} else {
		printf("Pixels: NULL");
	}
}
