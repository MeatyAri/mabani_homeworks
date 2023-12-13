#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int inp, n;
    cin >> n;
    int v[n], out[n];
    for (int i=0; i<n; i++) {
        cin >> inp;
        v[i] = inp;
    }

    sort(v, v + sizeof(v)/sizeof(v[0]));

    for (int io=0, iv=0; io<n; io += 2, iv++) {
        out[io] = v[n-iv-1];
        out[io+1] = v[iv];
    }

    for (int i=0; i<n; i++) {
        cout << out[i] << ' ';
    }

  return 0;
}
