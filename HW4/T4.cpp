#include <iostream>
#include <map>
#include <limits>
using namespace std;

map<int, float> off_map = {
    {1e6, 0.95},
    {3e6, 0.9},
    {numeric_limits<int>::max(), 0.85},
};

float off_calc(int inp){
    for (const auto& [key, val] : off_map) {
        if (inp <= key) {
            return inp * val;
        }
    }
    return 1;
}

int main(){
    int inp;
    cin >> inp;

    printf("%.0f", off_calc(inp));

    return 0;
}
