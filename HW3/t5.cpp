#include <iostream>
#include <string>
using namespace std;


int printhis(int val, string pm){
    if(val > 0){
        cout << val << pm;
    }
    return 0;
}

int main(){
    int remaining;
    cin >> remaining;

    int sad_t = static_cast<int>(remaining / 1e5);
    remaining = remaining - sad_t * 1e5;

    int panjah_t = static_cast<int>(remaining / 5e4);
    remaining = remaining - panjah_t * 5e4;

    int dah_t = static_cast<int>(remaining / 1e4);
    remaining = remaining - dah_t * 1e4;

    int panj_t = static_cast<int>(remaining / 5e3);
    remaining = remaining - panj_t * 5e3;

    printhis(sad_t, " ta 100 tayi\n");
    printhis(panjah_t, " ta 50 tayi\n");
    printhis(dah_t, " ta 10 tayi\n");
    printhis(panj_t, " ta 5 tayi");

    return 0;
}
