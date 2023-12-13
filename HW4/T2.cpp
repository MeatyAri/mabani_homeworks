#include <iostream>
using namespace std;

int main(){
    int inp;
    cin >> inp;

    if (!(inp % 2))
        cout << "even";
    else
        cout << "odd";

    return 0;
}
