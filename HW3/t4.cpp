#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "A=" << a << "\nB=" << b << endl;

    return 0;
}
