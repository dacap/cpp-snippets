#include "filesystem_wrapper.h"
#include <iostream>

int main() {
  path curdir = current_path<path>();
  directory_iterator end;
  for (directory_iterator it(curdir); it != end; ++it) {
    std::cout << it->path().filename() << "\n";
  }
}
