#include <bits/stdc++.h>
#include "../include/Data.h"

struct data_t {
	int 	n;
	int* 	vecX;
	int* 	vecY;
	bool** 	compatibilityMtx;
};

void readData( Data data ) {

	int i, j;

	FILE* fp;

	if ( !( fp = fopen("../../instancias/15.txt", "r") ) ) {
        printf("Erro na abertura do arquivo.\n");
        exit( EXIT_FAILURE );
    }

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

Data new_data() {

    Data data = ( Data ) malloc( sizeof(struct data_t) );

    readData(data);

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
