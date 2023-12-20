#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int num){

    if(num < 2) return false;
    if(num == 2) return true;
    if(num % 2 == 0) return false;
    for(int i=3; (i*i)<=num; i+=2){
        if(num % i == 0 ) return false;
    }
    return true;

}

bool is_perfect_square(int num) {
    long long int sq = sqrt(num);
    return (sq * sq == num);
}

long long int sq_sum(int num) {
    long long int sum = 0;
    for (int i=1; (i*i)<num; i++) {
        sum += i*i;
    }
    return sum;
}

long long int p_sum(int num) {
    long long int sum = 0;
    for (int i=1; i<num; i++) {
        if (is_prime(i))
            sum += i;
    }
    return sum;
}

int main(){
    int inp;
    cin >> inp;

    if (is_prime(inp)) {
        cout << sq_sum(inp);
    }
    else if (is_perfect_square(inp)) {
        cout << p_sum(inp);
    }
    else {
        cout << inp;
    }

    return 0;
}