#include <iostream>

constexpr int test01() {
  constexpr auto a = 42;
  return a;
}

constexpr int test02() { return 44; }

constexpr int test03() { return test01() * test02(); }

class A {
public:
  int a;
  int get() { return a; }
  void dump() { std::cout << "a : " << std::hex << &a << std::endl; }

  // コピーコンストラクター
  A(const A &) = delete;
  // コピー代入演算子
  A &operator=(const A &) = delete;

  // デフォルトコンストラクター
  A() = delete;
  A(int _a) : a(_a) {}
  // ムーブコンストラクター
//  A(A &&) {}
  // ムーブ代入演算子
//  A &operator=(A &&) {}
};

int main() {
  A a(3);
  a.dump();
  A&& b = std::move(a);

  b.dump();
  a.dump();
  return 0;
}
