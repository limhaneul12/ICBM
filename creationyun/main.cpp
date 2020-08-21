#include "malware_unzip.h"

int main(int argc, char *argv[])
{
	if (argc != 4) {
		printf("usage: %s <gz_filepath> <maldataset_dir> <inflate_filename>\n", argv[0]);
		return 0;
	}
	
	malware_unzip(argv[1], argv[2], argv[3]);
	return 0;
}

