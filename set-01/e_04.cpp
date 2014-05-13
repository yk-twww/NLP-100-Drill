#include <iostream>
#include <fstream>
#include <string>



int main()
{
  std::string line1, line2;
  std::ifstream ifs1("col1.txt");
  std::ifstream ifs2("col2.txt");

  while (getline(ifs1, line1) && getline(ifs2, line2)) {
    std::cout << line1 << "\t" << line2 << std::endl;
  }

  ifs1.close();
  ifs2.close();

  return 0;
}
