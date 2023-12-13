#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    float pi=3.14, r;
    cin >> r;

    float p = 2 * pi * r;
    float s = pi * pow(r, 2);

    printf("%.2f\n", p);
    printf("%.2f\n", s);

    return 0;
}
