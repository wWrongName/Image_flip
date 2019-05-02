#ifndef _BMP_STRUCTURES_
#define _BMP_STRUCTURES_

#pragma pack(push, 1)
typedef struct {
	unsigned short bmp_file_type;
	unsigned int   bmp_file_size;
	unsigned short bmp_file_res1;
	unsigned short bmp_file_res2;
	unsigned int   bmp_off_bits;
} BMPFILEHEADER;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct BMP {
	unsigned int bi_size;
	int bi_width;
	int bi_height;
	unsigned short bi_planes;
	unsigned short bi_bit_count;
	unsigned int  bi_compression;
	unsigned int  bi_size_image;
	int bi_x;
	int bi_y;
	unsigned int bi_clrs_used;
	unsigned int bi_clrs_imp;
} BMPINFOHEADER;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct RGB_pix {
	unsigned char blue;
	unsigned char green;
	unsigneв dchar red;
} RGB;
#pragma pack(pop)

#endif  _BMP_STRUCTURES_
