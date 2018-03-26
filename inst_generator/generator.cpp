#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

void simple_dist(int n) {

    int i, start = 1;

	for ( i = 0; i < n; i++ ) {
		printf("%d\n", start);
		start += rand()%2 + 2;
	}

	start = 1;
	for ( i = 0; i < n; i++ ) {
		printf("%d\n", start);
		start += rand()%2 + 2;
	}
}

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

    vec[vec.size()-1]--;

    for ( long long int i = 0; i < vec.size()*2; i++ ) {
        printf("%lld\n", vec[i%n]);
    }
}

int main( int argc, char* argv[] ) {

    char type;
    long long int n;

    sscanf(argv[1], "%lld", &n);
    sscanf(argv[2], "%c", &type);

    printf("%lld\n", n);

    switch(type) {
        case 's':
            simple_dist(n);
            break;
        
        case 'b':
            bigdif_dist(n);
            break;

        case 'e':
            exp_dist(n);
            break;
    }

    return 0;
}
