#include "testlibrary/testlibrary.hpp"

namespace testlib {

int factorial(int input) noexcept {
    int result = 1;

    while (input > 0) {
        result *= input;
        --input;
    }

    return result;
}

}  // namespace testlib
