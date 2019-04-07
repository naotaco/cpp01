#include <iostream>

constexpr int test01() {
  constexpr auto a = 42;
  return a;
}

constexpr int test02() { return 44; }

constexpr int test03() { return test01() * test02(); }

int main() {
  std::cout << test03();
  return 0;
}
