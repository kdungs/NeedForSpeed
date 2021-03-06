#include "helpers.hpp"

__attribute__ ((noinline)) void funWithFlagParam(bool flag) {
  if (flag) {
    doSomething();
  } else {
    doSomethingElse();
  }
}

template <bool FLAG>
__attribute__ ((noinline)) void funWithFlagTpl() {
  if (FLAG) {
    doSomething();
  } else {
    doSomethingElse();
  }
}

int main() {
  funWithFlagParam(true);
  funWithFlagParam(false);
  funWithFlagTpl<true>();
  funWithFlagTpl<false>();
}
