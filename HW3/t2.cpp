#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    int t, f;
    cin >> t >> f;

    float score = static_cast<float>(t * 3 - f) / 90 * 20;
    float percentage = static_cast<float>(t * 3 - f) / 90 * 100;

    printf("%.2f\n", trunc(score*100.0)/100.0);
    printf("%.2f\n", trunc(percentage*100.0)/100.0);

    return 0;
}
