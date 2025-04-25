TEX2PNG_C_FILES := \
    src/tex2png.c \
    src/libpdtex/pdtex.c \
    src/libpdtex/reader.c \
    src/libpdtex/writer.c

# Compile tex2png, ensuring the build directory exists first
tex2png: $(TEX2PNG_C_FILES)
	mkdir -p build
	gcc $(TEX2PNG_C_FILES) -lpng -lz -O3 -o build/tex2png

clean:
	rm -f build/tex2png

default: tex2png