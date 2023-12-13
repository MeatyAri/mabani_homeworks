#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    if (n % 2) {
        n += 1;
    }
    else
        n += 2;
    for (int i=n;i<m;i+=2) {
        cout << i << ' ';
    }

    return 0;
}
