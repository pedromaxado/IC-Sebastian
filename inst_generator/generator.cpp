#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

void bigdif_dist(int n) {

    int i;

    for ( i = 0; i < n; i++ ) {
        printf("%d\n", i);
    }

    for ( i = 0; i < n; i++ ) {
        printf("%d\n", i*n);
    }
}

void exp_dist(long long int n) {

    vector<long long int> vec;

    for ( long long int i = 0; i < n; i++ ) {
        long long int sum = 0;

        for ( long long int j = 0; j < i; j++ ) {
            sum += pow(2, (n-j));
        }

        vec.push_back(sum);
    }

    for ( long long int i = 0; i < vec.size()*2; i++ ) {
        printf("%lld\n", vec[i%n]);
    }
}

int main( int argc, char* argv[] ) {

    long long int n;

    sscanf(argv[1], "%lld", &n);

    printf("%lld\n", n);

    exp_dist(n);

    return 0;
}
