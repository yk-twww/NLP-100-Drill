#include <iostream>
#include <algorithm>
#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <utility>


class CompPair
{
public:
  bool operator()(const std::pair<std::string, std::string>& a,
		  const std::pair<std::string, std::string>& b)
  {
    if (a.second != b.second) {
      return a.second < b.second;
    } else {
      return a.first < b.first;
    }
  }
};



int main()
{
  std::string line;
  std::vector<std::string> str_vec;
  std::vector< std::pair<std::string, std::string> > columns;
  std::pair<std::string, std::string> column;


  while (getline(std::cin, line)) {
    boost::algorithm::split(str_vec, line, boost::is_any_of("\t"));
    column.first  = str_vec[0];
    column.second = str_vec[1];
    columns.push_back(column);
  }

  std::sort(columns.begin(), columns.end(), CompPair());

  std::vector< std::pair<std::string, std::string> >::iterator iter;
  for (iter = columns.begin(); iter != columns.end(); iter++) {
    std::cout << (*iter).first << "\t" << (*iter).second << std::endl;
  }

  return 0;
}
