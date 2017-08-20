#include <bits/stdc++.h>
#include "../include/CompatFunction.h"
#include "../include/Heap.h"
#include "../include/AlgHeap.h"
#include "../include/Data.h"

using namespace std;

pair<int, int> AlgHeap( int n, int* vecX, int* vecY, bool** resultMtx, Heap h, int** hash ) {

    Pair stack[2*n];
    int stsize;

    Pair p, q;
    pair<int, int> res;

    p.sum = vecX[0] + vecY[0];
    p.x_ind = 0;
    p.y_ind = 0;

    h_insert( h, p );

    stack[0].x_ind = 0;
    stack[0].y_ind = 0;

    stsize = 1;

    hash[0][0] = 0;

    bool found = false;

    while ( h_size(h) > 0 && !found ) {

        p = h_root(h);

        if ( resultMtx[p.x_ind][p.y_ind] ) {
            res.first  = p.x_ind;
            res.second = p.y_ind;
            found = true;
        }
        else {
            h_extract_min(h);

            stsize--;
            stack[hash[p.x_ind][p.y_ind]] = stack[stsize];
            hash[stack[stsize].x_ind][stack[stsize].y_ind]=hash[p.x_ind][p.y_ind];

            if  ( p.x_ind + 1 < n && !(hash[p.x_ind + 1][p.y_ind] < stsize   &&
                  stack[hash[p.x_ind + 1][p.y_ind]].x_ind == p.x_ind + 1     &&
                  stack[hash[p.x_ind + 1][p.y_ind]].y_ind == p.y_ind)
                ) {
                q.x_ind = p.x_ind + 1;
                q.y_ind = p.y_ind;
                q.sum   = vecX[q.x_ind]+vecY[q.y_ind];

                h_insert(h, q);

                stack[stsize].x_ind = q.x_ind;
                stack[stsize].y_ind = q.y_ind;

                hash[q.x_ind][q.y_ind] = stsize;
                stsize++;
            }

            if  ( p.y_ind + 1 < n && !(hash[p.x_ind][p.y_ind+1] < stsize &&
                  stack[hash[p.x_ind][p.y_ind+1]].x_ind == p.x_ind &&
                  stack[hash[p.x_ind][p.y_ind+1]].y_ind == p.y_ind+1)
                ) {
                q.x_ind = p.x_ind;
                q.y_ind = p.y_ind + 1;
                q.sum   = vecX[q.x_ind]+vecY[q.y_ind];

                h_insert(h, q);

                stack[stsize].x_ind = q.x_ind;
                stack[stsize].y_ind = q.y_ind;

                hash[q.x_ind][q.y_ind] = stsize;
                stsize++;
            }
        }
    }

    if ( found )
        return res;
    else
        return make_pair(-1,-1);
}

pair<int, int> AlgHeap( int n, int* vecX, int* vecY, const int PROB, Heap h ) {
    return make_pair(-1,-1);
}
