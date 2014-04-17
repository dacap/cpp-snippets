#include <iostream>
#include <string>

int main() {
  std::cout << "Write 'exit' to finish the program." << std::endl;

  std::string line;
  while (std::getline(std::cin, line)) {
    if (line == "exit")
      break;

    std::cout << line << std::endl;
  }
}
