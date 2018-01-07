#ifndef _FILEHANDLER_H_
#define _FILEHANDLER_H_

#include <iostream>

FILE* open_file( const char* path, const char* mode );

void close_file( FILE* fp );

#endif
