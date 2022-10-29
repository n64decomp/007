#ifndef IN_PDTEX_H
#define IN_PDTEX_H
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define PDTEX_MAX_IMAGES 7

enum pd_format {
	PDFORMAT_RGBA32,
	PDFORMAT_RGBA16,
	PDFORMAT_RGB24,
	PDFORMAT_RGB15,
	PDFORMAT_IA16,
	PDFORMAT_IA8,
	PDFORMAT_IA4,
	PDFORMAT_I8,
	PDFORMAT_I4,
	PDFORMAT_RGBA16_CI8,
	PDFORMAT_RGBA16_CI4,
	PDFORMAT_IA16_CI8,
	PDFORMAT_IA4_CI4,
};

enum pd_compression {
	PDCOMPRESSION_HUFFMAN = 2,
	PDCOMPRESSION_HUFFMANPERHCHANNEL,
	PDCOMPRESSION_RLE,
	PDCOMPRESSION_LOOKUP,
	PDCOMPRESSION_HUFFMANLOOKUP,
	PDCOMPRESSION_RLELOOKUP,
	PDCOMPRESSION_HUFFMANBLUR,
	PDCOMPRESSION_RLEBLUR,
};

struct pd_image {
	bool exists;
	enum pd_format format;
	enum pd_compression compression;
	int width;
	int height;
	uint8_t *pixels;
};

struct pd_tex {
	uint8_t *palette;
	int numcolours;
	struct pd_image images[PDTEX_MAX_IMAGES];
};

struct pd_tex *pdtex_allocate(void);

void pdtex_free(struct pd_tex *tex);

int pdtex_read(struct pd_tex *tex, char *filename);

int pdtex_write(struct pd_image *image, char *filename);

void pdtex_print(struct pd_tex *tex);

#endif
