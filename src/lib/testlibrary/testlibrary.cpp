#include "testlibrary/testlibrary.hpp"

namespace testlib {

uint32_t factorial(uint32_t input) noexcept {
    uint32_t result = 1;

    while (input > 0) {
        result *= input;
        --input;
    }

    return result;
}

}  // namespace testlib
