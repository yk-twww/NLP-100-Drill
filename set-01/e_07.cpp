#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <set>



int main()
{
  std::string line;
  std::vector<std::string> str_vec;
  std::set<std::string> diff_col1;

  while (getline(std::cin, line)) {
    boost::algorithm::split(str_vec, line, boost::is_any_of("\t"));
    diff_col1.insert(str_vec[0]);
  }

  std::cout << diff_col1.size() << std::endl;

  return 0;
}
