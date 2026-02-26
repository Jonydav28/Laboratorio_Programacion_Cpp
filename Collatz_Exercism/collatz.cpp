#include <stdexcept>

int steps(int n) {
    if (n <= 0) {
        throw std::invalid_argument("Only positive integers are allowed");
    }

    int count = 0;

    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        count++;
    }

    return count;
}
