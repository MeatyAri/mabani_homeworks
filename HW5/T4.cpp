#include <iostream>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    int gcd=1;

    for (int i=2;i<min(n, m);i++) {
        if (!(m % i) && !(n % i))
            gcd = i;
    }

    cout << gcd;

    return 0;
}
