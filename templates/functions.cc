#include "helpers.hpp"

__attribute__ ((noinline)) void doPtr(void (*f)()) { f(); }

template <typename FN>
__attribute__ ((noinline)) void doTpl(FN f) {
  f();
}

int main() {
  doPtr(doSomething);
  doPtr(doSomethingElse);
  doTpl(doSomething);
  doTpl(doSomethingElse);
}
