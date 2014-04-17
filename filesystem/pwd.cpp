#include "filesystem_wrapper.h"
#include <iostream>

using namespace std::tr2::sys;

int main() {
  std::cout << current_path<path>() << "\n";
}
