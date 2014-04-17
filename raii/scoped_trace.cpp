#include <iostream>
#include "scoped_trace.h"

void func2() {
  SCOPED_TRACE(func2);
}

void func1() {
  SCOPED_TRACE(func1);
  func2();
}

int main() {
  func1();
}
