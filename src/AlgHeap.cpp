#include "../include/CompatFunction.h"
// #include "../include/Data.h"
// #include "../include/Heap.h"
#include "../include/AlgHeapUtils.h"
#include "../include/AlgHeap.h"

#include <set>

using namespace std;

// using namespace std;
//
// pair<int, int> AlgHeap( int n, int* vecX, int* vecY, bool** resultMtx, Heap h, int** hash ) {
//
//     Pair stack[2*n];
//     int stsize;
//
//     Pair p, q;
//     pair<int, int> res;
//
//     p.sum = vecX[0] + vecY[0];
//     p.x_ind = 0;
//     p.y_ind = 0;
//
//     h_insert( h, p );
//
//     stack[0].x_ind = 0;
//     stack[0].y_ind = 0;
//
//     stsize = 1;
//
//     hash[0][0] = 0;
//
//     bool found = false;
//
//     while ( h_size(h) > 0 && !found ) {
//
//         p = h_root(h);
//
//         if ( resultMtx[p.x_ind][p.y_ind] ) {
//             res.first  = p.x_ind;
//             res.second = p.y_ind;
//             found = true;
//         }
//         else {
//             h_extract_min(h);
//
//             stsize--;
//             stack[hash[p.x_ind][p.y_ind]] = stack[stsize];
//             hash[stack[stsize].x_ind][stack[stsize].y_ind]=hash[p.x_ind][p.y_ind];
//
//             if  ( p.x_ind + 1 < n && !(hash[p.x_ind + 1][p.y_ind] < stsize   &&
//                   stack[hash[p.x_ind + 1][p.y_ind]].x_ind == p.x_ind + 1     &&
//                   stack[hash[p.x_ind + 1][p.y_ind]].y_ind == p.y_ind)
//                 ) {
//                 q.x_ind = p.x_ind + 1;
//                 q.y_ind = p.y_ind;
//                 q.sum   = vecX[q.x_ind]+vecY[q.y_ind];
//
//                 h_insert(h, q);
//
//                 stack[stsize].x_ind = q.x_ind;
//                 stack[stsize].y_ind = q.y_ind;
//
//                 hash[q.x_ind][q.y_ind] = stsize;
//                 stsize++;
//             }
//
//             if  ( p.y_ind + 1 < n && !(hash[p.x_ind][p.y_ind+1] < stsize &&
//                   stack[hash[p.x_ind][p.y_ind+1]].x_ind == p.x_ind &&
//                   stack[hash[p.x_ind][p.y_ind+1]].y_ind == p.y_ind+1)
//                 ) {
//                 q.x_ind = p.x_ind;
//                 q.y_ind = p.y_ind + 1;
//                 q.sum   = vecX[q.x_ind]+vecY[q.y_ind];
//
//                 h_insert(h, q);
//
//                 stack[stsize].x_ind = q.x_ind;
//                 stack[stsize].y_ind = q.y_ind;
//
//                 hash[q.x_ind][q.y_ind] = stsize;
//                 stsize++;
//             }
//         }
//     }
//
//     if ( found )
//         return res;
//     else
//         return make_pair(-1,-1);
// }
//
// pair<int, int> AlgHeap( int n, int* vecX, int* vecY, const int PROB, Heap h ) {
//     return make_pair(-1,-1);
// }

void h_insert (heap* h, Pair p) {
    h->data[h->size]=p;
    int i=h->size;
    while ((h->data[i/2]).sum > (h->data[i]).sum) {
        Pair aux = h->data[i/2];
        h->data[i/2]=h->data[i];
        h->data[i]=aux;
        i/=2;
    }
    h->size++;
}

void heapify (heap* h, int i) {
    int l = 2*i+1;
    int r = 2*i+2;
    int sm;
    if (l<h->size && h->data[l].sum<h->data[i].sum) {
        sm=l;
    } else {
        sm=i;
    }
    if (r<h->size && h->data[r].sum<h->data[sm].sum) {
        sm=r;
    }
    if (sm!=i) {
        Pair aux = h->data[i];
        h->data[i]=h->data[sm];
        h->data[sm]=aux;
        heapify (h,sm);
    }
}

void h_extractmin (heap* h) {
    h->data[0]=h->data[h->size-1];
    h->size--;
    heapify(h,0);
}

//see later MAX may not be enough

long long int AlgHeap( int n, long long int *vecX, long long int *vecY, bool **mtx, int* mina, int* minb, heap h, Pair *stack, unsigned int **hash ) {
    Pair p,q;
    unsigned int stsize;
    p.sum = vecX[0] + vecY[0];
    p.aind = 0;
    p.bind = 0;
    h.size=0;
    h_insert(&h, p);
    stack[0].aind=0;
    stack[0].bind=0;
    stsize=1;
    hash[0][0]=0;
    int found=0;
    while (h.size>0 && !found) {
        //    for (int i=0;i<h.size;i++) printf("|(%d %d) %d| ",h.data[i].aind, h.data[i].bind, h.data[i].sum);
        //    printf("\n");
        p=h.data[0];
        //    printf("par %d %d = %d\n",h.data[0].aind,h.data[0].bind,h.data[0].sum);
        if (mtx[p.aind][p.bind]) {
            *mina=p.aind;
            *minb=p.bind;
            found=1;
        } else {
            h_extractmin(&h);
            //      for (int i=0;i<h.size;i++) printf("|(%d %d) %d| ",h.data[i].aind, h.data[i].bind, h.data[i].sum);
            //      printf("\n");
            stsize--;
            stack[hash[p.aind][p.bind]]=stack[stsize];
            hash[stack[stsize].aind][stack[stsize].bind]=hash[p.aind][p.bind];

            if ( p.aind + 1 < n &&
                 !( hash[p.aind+1][p.bind] < stsize &&
                 stack[hash[p.aind+1][p.bind]].aind == p.aind + 1 &&
                 stack[hash[p.aind+1][p.bind]].bind == p.bind ) ) {

                q.aind=p.aind+1;
                q.bind=p.bind;
                q.sum=vecX[q.aind]+vecY[q.bind];
                h_insert(&h, q);
                stack[stsize].aind=q.aind;
                stack[stsize].bind=q.bind;
                hash[q.aind][q.bind]=stsize;
                stsize++;
            }

            if ( p.bind + 1 < n &&
                 !(hash[p.aind][p.bind+1] < stsize &&
                 stack[hash[p.aind][p.bind+1]].aind == p.aind &&
                 stack[hash[p.aind][p.bind+1]].bind == p.bind + 1 ) ) {

                q.aind=p.aind;
                q.bind=p.bind+1;
                q.sum=vecX[q.aind]+vecY[q.bind];
                h_insert(&h, q);
                stack[stsize].aind=q.aind;
                stack[stsize].bind=q.bind;
                hash[q.aind][q.bind]=stsize;
                stsize++;
            }
        }
    }
    if (found) return p.sum; else return -1;
}

long long int AlgHeap_Prob( int n, long long int *vecX, long long int *vecY, const int PROB, heap h, int a, int b, int c ) {

    Pair p,q;
    set<Pair> visited_pairs;
    unsigned int stsize;
    p.sum = vecX[0] + vecY[0];
    p.aind = 0;
    p.bind = 0;
    h.size=0;
    h_insert(&h, p);

    visited_pairs.insert(p);
    // stack[0].aind=0;
    // stack[0].bind=0;
    // stsize=1;
    // hash[0][0]=0;

    int found=0;
    while (h.size>0 && !found) {
        //    for (int i=0;i<h.size;i++) printf("|(%d %d) %d| ",h.data[i].aind, h.data[i].bind, h.data[i].sum);
        //    printf("\n");
        p=h.data[0];
        //    printf("par %d %d = %d\n",h.data[0].aind,h.data[0].bind,h.data[0].sum);
        if ( f_prob( PROB, a, b, c, p.aind, p.bind ) ) {
            // *mina=p.aind;
            // *minb=p.bind;
            found=1;
        } else {
            h_extractmin(&h);
            //      for (int i=0;i<h.size;i++) printf("|(%d %d) %d| ",h.data[i].aind, h.data[i].bind, h.data[i].sum);
            //      printf("\n");
            // stsize--;
            // stack[hash[p.aind][p.bind]]=stack[stsize];
            // hash[stack[stsize].aind][stack[stsize].bind]=hash[p.aind][p.bind];
            visited_pairs.erase(p);

            Pair aux = p;
            aux.aind += 1;

            if ( visited_pairs.find(aux) != visited_pairs.end() ) {
            // if (p.aind+1<n && !(hash[p.aind+1][p.bind] < stsize &&
            //     stack[hash[p.aind+1][p.bind]].aind == p.aind+1 &&
            //     stack[hash[p.aind+1][p.bind]].bind == p.bind)) {

                q.aind=p.aind+1;
                q.bind=p.bind;
                q.sum=vecX[q.aind]+vecY[q.bind];
                h_insert(&h, q);
                visited_pairs.insert(q);
                // stack[stsize].aind=q.aind;
                // stack[stsize].bind=q.bind;
                // hash[q.aind][q.bind]=stsize;
                // stsize++;
            }

            aux = p;
            aux.bind += 1;

            if ( visited_pairs.find(aux) != visited_pairs.end() ) {
            // if (p.bind+1<n && !(hash[p.aind][p.bind+1] < stsize &&
            //     stack[hash[p.aind][p.bind+1]].aind == p.aind &&
            //     stack[hash[p.aind][p.bind+1]].bind == p.bind+1)) {

                q.aind=p.aind;
                q.bind=p.bind+1;
                q.sum=vecX[q.aind]+vecY[q.bind];
                h_insert(&h, q);
                visited_pairs.insert(q);
                // stack[stsize].aind=q.aind;
                // stack[stsize].bind=q.bind;
                // hash[q.aind][q.bind]=stsize;
                // stsize++;
            }
        }
    }
    if (found) return p.sum; else return -1;
}
