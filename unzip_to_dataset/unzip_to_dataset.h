#include <cstdio>
#include <zlib.h>
#include <dirent.h>
#include <cstdlib>
#include <cstring>
#include <libgen.h>

int inflate_mv_dataset(const char *gz_filepath, const char *maldataset_dir, const char *original_filename);
