#include <iostream>
using namespace std;


int main() {
    int end[100], start[100], inp;
    for (int i=0; i<100; i++) {
        cin >> inp;
        end[i] = inp;
    }

    for (int is=0, ie=0; is<100; is += 2, ie++) {
        start[is] = end[ie];
        start[is+1] = end[100-ie-1];
    }

    for (int i=0; i<100; i++) {
        cout << start[i] << ' ';
    }

    return 0;
}
