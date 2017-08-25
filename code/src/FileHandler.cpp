#include <iostream>
#include "../include/FileHandler.h"

FILE* open_file( const char* path, const char* mode ) {

    FILE* fp;

    if ( (fp = fopen(path, mode)) == NULL )
        exit(EXIT_FAILURE);

    return fp;
}

void close_file( FILE* fp ) {

    if ( fp )
        fclose(fp);
}
