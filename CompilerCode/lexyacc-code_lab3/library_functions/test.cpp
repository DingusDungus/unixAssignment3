#include <iostream>
#include <stdint.h>

extern "C" uint64_t inc_func(uint64_t x);
extern "C" uint64_t fact_func(uint64_t x);
extern "C" int64_t lntwo_func(int64_t x);
extern "C" int64_t gcd_func(int64_t x, int64_t y);

int main(int argc, char **argv) {
  std::cout << "test inc_func(add_one)" << std::endl;
  for (uint64_t i = 0; i < 10; ++i) {
    std::cout << "iteration: " << i << " inc value: " << inc_func(i)
              << std::endl;
  }

  std::cout << "test fact_func" << std::endl;
  std::cout << "res: " << fact_func(5) << std::endl;

  return 0;
}
