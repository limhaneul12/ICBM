#include "unzip_to_dataset.h"

int main(int argc, char *argv[])
{
	if (argc != 4) {
		printf("usage: %s <gz_filepath> <maldataset_dir> <inflate_filename>\n", argv[0]);
		return 0;
	}
	
	inflate_mv_dataset(argv[1], argv[2], argv[3]);
	return 0;
}

