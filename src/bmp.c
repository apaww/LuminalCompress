#include "../include/bmp.h"

BMPImage_t *bmpMalloc() {
    return malloc(sizeof(BMPImage_t));
}

int bmpLoad(const char *filename, BMPImage_t *image) {
    uint32_t data_address;
    uint32_t width, height;
    uint32_t pixel_count;
    uint16_t bit_depth;
    uint8_t byte_depth;
    uint32_t *pixels;

    FILE *file = fopen(filename, "rb");
    if (file) {
        if (fgetc(file) == 'B' && fgetc(file) == 'M') {
            fseek(file, 8, SEEK_CUR);
            fread(&data_address, 4, 1, file);
            fseek(file, 4, SEEK_CUR);
            fread(&width, 4, 1, file);
            fread(&height, 4, 1, file);
            fseek(file, 2, SEEK_CUR);
            fread(&bit_depth, 2, 1, file);
            
            if (data_address != 138) {

            } else if (bit_depth != 32) {

            } else {
                pixel_count = width * height;
                byte_depth = bit_depth / 8;

                pixels = malloc(pixel_count * byte_depth);
                if (pixels) {
                    fseek(file, data_address, SEEK_SET);

                    int pixels_read = fread(pixels, pixel_count, byte_depth, file);
                    if (pixels_read == pixel_count) {
                        image->width = width;
                        image->height = height;
                        image->pixels = pixels;
                        return 1;
                    } else {
                        free(pixels);
                    }
                }
            }
        }
    }

    return 0;
}

int bmpSave(const char *filename, BMPImage_t *image) {

}

void bmpFree(BMPImage_t *image) {

}