#include <iostream>
#include <string>
using namespace std;

int main() {
    int mat[3][3], non_z_counter=0, m, inp;
    string upper, lower;

    // input
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin >> inp;
            mat[i][j] = inp;
        }
    }

    m = mat[0][2];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            // non zero counter
            if (mat[i][j]) {
                non_z_counter++;
            }

            // finding the minimum of secondary diagonal elements
            if (i + j == 2) {
                if (mat[i][j] < m) {
                    m = mat[i][j];
                }
            }
            
            // printing main diagonal & upper triangular elements of the matrix
            if (i <= j) {
                upper += to_string(mat[i][j]) + ' ';
            }

            // printing lower triangular elements of the matrix
            if (i > j) {
                lower += to_string(mat[i][j]) + ' ';
            }
        }
    }

    cout << non_z_counter << '\n';
    cout << m << '\n';
    cout << upper << '\n';
    cout << lower;

    return 0;
}
