#include <iostream>
using namespace std;

long long int fact(int num) {
    long long int out=1;
    for (int i=2; i<=num; i++) {
        out *= i;
    }
    return out;
}

long long int calc(int n) {
    long long int sum = 0;
    for (int i=1; i<=n; i++) {
        if (i % 2) {
            sum += fact(i);
        }
        else {
            sum -= fact(i);
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    cout << calc(n);

    return 0;
}
