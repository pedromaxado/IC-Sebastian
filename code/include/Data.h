#ifndef _DATA_H_
#define _DATA_H_

typedef struct data_t* Data;

Data new_data();

void destroy_data( Data d );

int getSize( Data d );

int* getVecX( Data d );

int* getVecY( Data d );

bool** getCompatibilityMtx( Data d );

#endif
