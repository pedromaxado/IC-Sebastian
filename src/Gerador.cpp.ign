#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] ) {

	int n, i, j, ini, s;

	sscanf(argv[1],"%d",&s);
	srand(s);

	scanf("%d" ,&n);

	printf("%d\n", n);

	ini = 1;
	for (i=0; i<n; i++)
	{
		printf("%d\n", ini);
		ini += rand()%2 + 2;
	}

	ini = 1;
	for (i=0; i<n; i++) {
		printf("%d\n", ini);
		ini += rand()%2 + 2;
	}

	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < n; j++ ) {
			if ( i == n-1  && j == n-1 )
				printf("1 ");
			else
				printf("0 ");
		}
		printf("\n");
	}
}
