#include <iostream>
#include <string>


int main()
{
  int line_n;
  std::string line;

  line_n = 0;
  while (getline(std::cin, line)) {
    ++line_n;
  }

  std::cout << line_n << std::endl;
 
  return 0;
}
