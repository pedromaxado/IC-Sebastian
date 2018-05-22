#include <iostream>
#include <cstdlib>

#define SEED "seed_"

using namespace std;

int main() {

    FILE *in, *out;

    string path;
    string algs[4] = { "atrivial.csv", "diagonal.csv", "contourl.csv", "heap.csv" };

    char fodase;
    double value;
    double table[10][10];
    int ln_size = 4;
    int col_size = 6;

    for ( int k = 0; k < 4; k++ ) {

        for ( int i = 0; i < col_size; i++ )
            for ( int j = 0; j < col_size; j++ )
                table[i][j] = 0.00;

        for ( int s = 1; s <= 50; s++ ) {
            path = SEED + to_string(s) + "/" + algs[k];

            in = fopen( path.c_str(), "r" );
            cout << path <<  endl;
            for ( int i = 0; i < ln_size; i++ ) {
                fscanf(in, "\"%lf\"", &table[i][0]);
                fscanf(in, "%c", &fodase);
                cout << table[i][0] << " ";

                for ( int j = 1; j < col_size; j++ ) {
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

        for ( int i = 0; i < ln_size; i++ ) {
            fprintf(out, "\"%lf\"", table[i][0]);
            for ( int j = 1; j < col_size; j++ ) {
                table[i][j] /= 50.00;
                fprintf(out, ",\"%lf\"", table[i][j]);
            }
            fprintf(out, "\n");
        }

        fclose(out);
    }

    return 0;
}