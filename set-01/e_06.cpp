#include <iostream>
#include <cstdlib>
#include <string>
#include <deque>


int main(int argc, char** argv)
{
  int last_n = std::atoi(argv[1]);
  std::deque<std::string> lines;
  std::string line;

  int line_n = 0;
  while (getline(std::cin, line)) {
    if (lines.size() >= last_n) {
      lines.pop_front();
    }
    lines.push_back(line);
  }

  std::deque<std::string>::iterator iter;
  for (iter = lines.begin(); iter != lines.end(); iter++) {
    std::cout << *iter << std::endl;
  }
 
  return 0;
}
