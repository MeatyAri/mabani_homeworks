#include <iostream>
using namespace std;


bool is_dup(int* vec, int i) {
    for (int j=0; j<i; j++) {
        if (vec[i] == vec[j]) {
            return true;
        }
    }
    return false;
}

int main() {
    int vec[50], inp, end=50;
    for (int i=0; i<end; i++) {
        cin >> inp;
        if (inp < 0){
            end = i;
            break;
        }
        vec[i] = inp;
    }

    cout << '{';
    for (int i=0; i<end; i++) {
        if (!is_dup(vec, i)) {
            cout << vec[i];

            if (i != end-1) {
                cout << ", ";
            }
        }
    }
    cout << '}';
    return 0;
}
