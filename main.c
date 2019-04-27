#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#define BMP 19778


int main(int argc, char **argv)
{
	FILE *input = open_file(argc, argv);
	if (!input) return 1;

    BMPFILEHEADER fh;
	BMPINFOHEADER ih;
	
	fread(&fh, sizeof(BMPFILEHEADER), 1, input);
	if (fh.bmp_file_type != BMP)
	{
		printf("It is not BMP");
		fclose(input);
		return 1;
	}
	fread(&ih, sizeof(BMPINFOHEADER), 1, input);
	fseek(input, fh.bmp_off_bits, SEEK_SET);

	RGB **image;
	image = (RGB**)malloc(ih.bi_height * sizeof(RGB*));
	for (int i = 0; i < ih.bi_height; i++) {
		image[i] = (RGB*)malloc(ih.bi_width * sizeof(RGB));
	}

	read_image(input, image, ih.bi_height, ih.bi_width);

	flip_horizontally(image, ih.bi_height, ih.bi_width);

	fseek(input, fh.bmp_off_bits, SEEK_SET);

	write_image(input, image, ih.bi_height, ih.bi_width);
	printf("FLIPPED HORIZONTALLY");

	for (int i = 0; i < ih.bi_height; i++) {
		free(image[i]);
	}
	free(image);
	fclose(input);

	return 0;
}
