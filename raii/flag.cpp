#include <iostream>
#include "scoped_value.h"

int main() {
  bool flag = false;
  std::cout << "flag == " << flag << "\n"; // false
  {
    scoped_value<bool> switch_flag(flag, true, false);
    std::cout << "  flag == " << flag << "\n"; // true
    {
      scoped_value<bool> switch_flag(flag, false, true);
      std::cout << "    flag == " << flag << "\n"; // false
    }
  }
  std::cout << "flag == " << flag << "\n"; // false
}
