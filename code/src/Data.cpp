#include <iostream>
#include <cstdlib>
#include "../include/FileHandler.h"
#include "../include/Data.h"

using namespace std;

struct data_t {
	int 	n;
	int* 	vecX;
	int* 	vecY;
	bool** 	compatibilityMtx;
};

void readData( Data data, FILE* fp ) {

	int i, j;

    fscanf(fp, "%d", &data->n);

    data->vecX = ( int* ) malloc( data->n * sizeof(int) );
    data->vecY = ( int* ) malloc( data->n * sizeof(int) );

    data->compatibilityMtx = ( bool** ) malloc( data->n * sizeof( bool* ) );

    for ( i = 0; i < data->n; i++ )
    	data->compatibilityMtx[i] = ( bool* ) malloc( data->n * sizeof( bool ) );

    for ( i = 0; i < data->n; i++ )
   		fscanf(fp, "%d", &data->vecX[i]);

    for ( i = 0; i < data->n; i++ )
   		fscanf(fp, "%d", &data->vecY[i]);

    int aux;

   	for ( i = 0; i < data->n; i++ ) {
        for ( j = 0; j < data->n; j++ ) {
            fscanf(fp, "%d", &aux);
            data->compatibilityMtx[i][j] = aux;
        }
    }

	fclose(fp);
}

Data new_data( string path ) {

	FILE *fp = open_file( path.c_str(), "r" );

    Data data = ( Data ) malloc( sizeof(struct data_t) );

    readData(data, fp);

	close_file(fp);

    return data;
}

void destroy_data( Data data ) {

    free(data->vecX);
    free(data->vecY);

    for ( int i = 0; i < data->n; i++ ) {
        free(data->compatibilityMtx[i]);
    }

    free(data->compatibilityMtx);
    free(data);
}

int getSize( Data d ) {
	return d->n;
}

int* getVecX( Data d ) {
	return d->vecX;
}

int* getVecY( Data d ) {
	return d->vecY;
}

bool** getCompatibilityMtx( Data d ) {
	return d->compatibilityMtx;
}
