#include "unzip_to_dataset.h"

int inflate_mv_dataset(const char *gz_filepath, const char *maldataset_dir, const char *original_filename)
{
	gzFile zfp;
	char buf[1024];
	FILE *fp;
	char *new_filepath;
	
	// Open GZ file
	if ((zfp = gzopen(gz_filepath, "rb")) == NULL)
	{
		printf("Error: cannot read file (%s).\n", gz_filepath);
		return 1;	
	}

	// declare target file path
	size_t new_filepath_len = strlen(maldataset_dir) + strlen(original_filename) + 2;
	new_filepath = (char*) calloc(new_filepath_len, sizeof(char));
	
	if (new_filepath == NULL) {
		printf("Error: cannot allocate in heap memory.\n");
		return 1;	
	}

	// construct target file path
	sprintf(new_filepath, "%s/%s", maldataset_dir, original_filename);
	
	// write target file and decompress
	fp = fopen(new_filepath, "wb");

	while (gzgets(zfp, buf, 1023) != NULL)
	{
		fprintf(fp, "%s", buf);
	}

	// close target file
	fclose(fp);

	// close GZ file
	gzclose(zfp);

	return 0;
}

