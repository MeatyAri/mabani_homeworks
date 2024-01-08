#include <iostream>
#include <cmath>
using namespace std;


double S(double n) {
    if (n == 1) {
        return n;
    }
    return pow(n, 2) + S(n-1);
}

int main() {
    double n;
    cin >> n;
    cout << S(n);
    return 0;
}