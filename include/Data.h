#ifndef _DATA_H_
#define _DATA_H_

#include <iostream>

#define PROB_MOD 1
#define MTX_MOD  0

using namespace std;

typedef struct data_t* Data;

Data new_data( string path, int mode );

void destroy_data( Data d );

int getSize( Data d );

long long int* getVecX( Data d );

long long int* getVecY( Data d );

bool** getCompatibilityMtx( Data d );

#endif
