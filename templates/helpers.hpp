#pragma once

template <class T>
void doNotOptimizeAway(T&& datum) {
  asm volatile("" : "+r" (datum));
}

__attribute__ ((noinline)) void doSomething() { doNotOptimizeAway(42); }
__attribute__ ((noinline)) void doSomethingElse() { doNotOptimizeAway(23); }
