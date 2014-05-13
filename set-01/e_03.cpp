#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>



int main()
{
  std::string line;
  std::vector<std::string> str_vec;
  std::ofstream ofs1("col1.txt");
  std::ofstream ofs2("col2.txt");

  while (getline(std::cin, line)) {
    boost::algorithm::split(str_vec, line, boost::is_any_of("\t"));
    ofs1 << str_vec[0] << std::endl;
    ofs2 << str_vec[1] << std::endl;
  }

  ofs1.close();
  ofs2.close();

  return 0;
}
