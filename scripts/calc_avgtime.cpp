#include <iostream>
#include <cstdlib>

#define SEED "seed_"

using namespace std;

int main() {

    FILE *in, *out;

    string path;
    string algs[5] = { "trivial.csv", "atrivial.csv", "diagonal.csv", "contourl.csv", "heap.csv" };

    char fodase;
    double value;
    double table[10][10];

    for ( int k = 0; k < 5; k++ ) {

        for ( int i = 0; i < 5; i++ )
            for ( int j = 0; j < 5; j++ )
                table[i][j] = 0.00;

        for ( int s = 1; s <= 50; s++ ) {
            path = SEED + to_string(s) + "/" + algs[k];

            in = fopen( path.c_str(), "r" );
            cout << path <<  endl;
            for ( int i = 0; i < 4; i++ ) {
                fscanf(in, "\"%lf\"", &table[i][0]);
                fscanf(in, "%c", &fodase);
                cout << table[i][0] << " ";

                for ( int j = 1; j < 5; j++ ) {
                    fscanf(in, "\"%lf\"", &value);
                    fscanf(in, "%c", &fodase);

                    table[i][j] += value;

                    printf("%lf ", value);
                }

                cout << endl;
            }
            cout << s << endl;

            fclose(in);
        }

        out = fopen( algs[k].c_str() , "w" );

        for ( int i = 0; i < 4; i++ ) {
            fprintf(out, "\"%lf\"", table[i][0]);
            for ( int j = 1; j < 5; j++ ) {
                table[i][j] /= 50.00;
                fprintf(out, ",\"%lf\"", table[i][j]);
            }
            fprintf(out, "\n");
        }

        fclose(out);
    }

    return 0;
}
