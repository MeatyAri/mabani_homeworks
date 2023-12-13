#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int num;
    cin >> num;

    for (int i=pow(10, to_string(num).length()-1);i>0;i /= 10) {
        int digit = num / i % 10;
        string asts(digit, '*');
        cout << digit << ' ' << asts << '\n';
    }

    return 0;
}
