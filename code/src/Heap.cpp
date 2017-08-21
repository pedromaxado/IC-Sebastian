#include <cstdlib>
#include "../include/Heap.h"

struct heap_t {
    Pair* data;
    int size;
};

Heap new_heap( int size ) {

    Heap h = ( Heap ) malloc( sizeof(struct heap_t) );

    h->size = size;
    h->data = ( Pair* ) malloc( size * sizeof( struct pair_t ) );

    return h;
}

void destroy_heap( Heap h ) {

    if ( h == NULL )
        return;

    free(h->data);
    free(h);
}

int h_size( Heap h ) {
    return h->size;
}

void heapify( Heap h, int i ) {

    int l = 2*i+1;
    int r = 2*i+2;
    int sm;

    if ( l < h->size and h->data[l].sum < h->data[i].sum)
        sm = l;
    else
        sm = i;

    if ( r < h->size and h->data[r].sum < h->data[sm].sum )
        sm=r;

    if ( sm != i ) {
        Pair aux    = h->data[i];
        h->data[i]  = h->data[sm];
        h->data[sm] = aux;

        heapify ( h, sm );
    }
}

Pair h_root( Heap h ) {
    return h->data[0];
}

void h_insert( Heap h, Pair p ) {

    h->data[h->size]=p;

    int i = h->size;

    while ( ( h->data[i/2] ).sum > ( h->data[i]).sum ) {
        Pair aux     = h->data[i/2];
        h->data[i/2] = h->data[i];
        h->data[i]   = aux;
        i /= 2;
    }

    h->size++;
}

void h_extract_min( Heap h ) {

    h->data[0] = h->data[h->size-1];
    h->size--;

    heapify(h,0);
}
