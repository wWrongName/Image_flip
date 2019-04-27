#include "bmp.h"
#include <stdio.h>

void flip_horizontally(RGB **image, int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width / 2; j++) {
			RGB temp = image[i][j];
			image[i][j] = image[i][width - j];
			image[i][width - j] = temp;
		}
	}
}

void read_image(FILE *ptr, RGB **image, int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			fread(&image[i][j], sizeof(RGB), 1, ptr);
		}
	}
}

void write_image(FILE *ptr, RGB **image, int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			fwrite(&image[i][j], sizeof(RGB), 1, ptr);
		}
	}
}

FILE *open_file(int argc, char **argv) {
	if (argc != 3) {
		printf("Incorrect input. Example: prog.exe -i image.bmp\n");
		return NULL;
	}
	if (strcmp(argv[1], "-i")) {
		printf("Incorrect input. Example: prog.exe -i image.bmp\n");
		return NULL;
	}
	FILE* input = fopen(argv[2], "rb+");
	if (input == NULL) {
		printf("ERROR: Input file (");
		printf(argv[2]);
		printf(") is not found\n");
		return NULL;
	}
	return input;
}
