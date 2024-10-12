#ifndef MYPROJECT_TESTLIBRARY_H
#define MYPROJECT_TESTLIBRARY_H

#include <stdint.h>

namespace testlib {

/**
 * @brief Computes the factorial of the input value.
 *
 * @param input Integer number. It must be non-negative.
 */
uint32_t factorial(uint32_t input) noexcept;

}  // namespace testlib

#endif
