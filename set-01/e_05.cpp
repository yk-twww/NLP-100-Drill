#include <iostream>
#include <cstdlib>
#include <string>


int main(int argc, char** argv)
{
  int first_n = std::atoi(argv[1]);
  std::string line;

  int line_n = 0;
  while (getline(std::cin, line) && line_n < first_n) {
    std::cout << line << std::endl;
    ++line_n;
  }
 
  return 0;
}
