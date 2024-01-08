#include <iostream>

int test(int *b) {
    int a = 4;
    *b = *b < 10 ? *b : 2 * *b;
    return a + *b;
}

int main() {
    int a = 10;
    int result = test(&a);
    std::cout << a;
    return 0;
}
