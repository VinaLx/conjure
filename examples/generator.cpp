#include "conjure/interfaces.h"
#include "conjure/gen-iterator.h"
#include <stdio.h>

using namespace conjure;

Generating<int> Fibonacci(int n) {
    int x = 0, y = 1;
    for (int i = 0; i < n; ++i) {
        printf("yielding %d\n", x);
        YieldWith(x);
        int t = x + y;
        x = y;
        y = t;
    }
    return {};
}

int main() {
    auto co = Conjure(Config{}, Fibonacci, 10);
    for (int i : co) {
        // 0 1 1 2 3 5 8 13 21 34
        printf("main: %d\n", i);
    }
}
