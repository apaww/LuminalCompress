#ifndef BMP_H
#define BMP_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t *pixels;
} BMPImage_t;

BMPImage_t *bmpMalloc();
int bmpLoad(const char *filename, BMPImage_t *image);
int bmpSave(const char *filename, BMPImage_t *image);
void bmpFree(BMPImage_t *image);

#endif