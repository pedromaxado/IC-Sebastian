#include <iostream>
#include <fstream>
#include <cstdlib>
#include "../include/FileHandler.h"
#include "../include/Data.h"

using namespace std;

struct data_t {
	int 	n;
	long long int* 	vecX;
	long long int* 	vecY;
	bool** 	compatibilityMtx;

	int mode;
};

void readData( Data data, string path ) {

	ifstream fp_inst;
	int i;

	fp_inst.open( path, ifstream::in );

	if ( fp_inst.fail() ) {
		cout << "ERROR opening file: " << path << endl;
		exit(EXIT_FAILURE);
	}

	fp_inst >> data->n;

    data->vecX = ( long long int* ) malloc( data->n * sizeof(long long int) );
    data->vecY = ( long long int* ) malloc( data->n * sizeof(long long int) );

    for ( i = 0; i < data->n; i++ )
		fp_inst >> data->vecX[i];

    for ( i = 0; i < data->n; i++ )
   		fp_inst >> data->vecY[i];

	if ( data->mode == MTX_MOD ) {
		int j;

		data->compatibilityMtx = ( bool** ) malloc( data->n * sizeof( bool* ) );

	    for ( i = 0; i < data->n; i++ )
	    	data->compatibilityMtx[i] = ( bool* ) malloc( data->n * sizeof( bool ) );

	    int aux;

	   	for ( i = 0; i < data->n; i++ ) {
	        for ( j = 0; j < data->n; j++ ) {
	            fp_inst >> aux;
	            data->compatibilityMtx[i][j] = aux;
	        }
	    }
	}

	fp_inst.close();
}

Data new_data( string path, int mode ) {

    Data data = ( Data ) malloc( sizeof(struct data_t) );

	data->mode = mode;
    readData( data, path );

    return data;
}

void destroy_data( Data data ) {

    free(data->vecX);
    free(data->vecY);

	if ( data->mode == MTX_MOD ) {
		for ( int i = 0; i < data->n; i++ ) {
			free(data->compatibilityMtx[i]);
		}

		free(data->compatibilityMtx);
	}

    free(data);
}

int getSize( Data d ) {
	return d->n;
}

long long int* getVecX( Data d ) {
	return d->vecX;
}

long long int* getVecY( Data d ) {
	return d->vecY;
}

bool** getCompatibilityMtx( Data d ) {
	return d->compatibilityMtx;
}
