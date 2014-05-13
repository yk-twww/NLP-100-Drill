#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>


class CompPair
{
public:
  bool operator()(const std::pair<std::string, int>& a,
		  const std::pair<std::string, int>& b)
  {
    return a.second > b.second;
  }
};


int main()
{
  std::string line;
  std::ifstream ifs("col2.txt");
  std::map<std::string, int> counter;

  while (getline(ifs, line)) {
    if (counter.find(line) == counter.end()) {
      counter[line] = 1;
    } else {
      counter[line] = (*counter.find(line)).second + 1;
    }
  }

  std::vector< std::pair<std::string, int> > line_freqs;
  std::pair<std::string, int> line_freq;
  std::map<std::string, int>::iterator m_iter;
  for (m_iter = counter.begin(); m_iter != counter.end(); m_iter++) {
    line_freq.first  = (*m_iter).first;
    line_freq.second = (*m_iter).second;
    line_freqs.push_back(line_freq);
  }

  std::sort(line_freqs.begin(), line_freqs.end(), CompPair());

  std::vector< std::pair<std::string, int> >::iterator v_iter;
  for (v_iter = line_freqs.begin(); v_iter != line_freqs.end(); v_iter++) {
    std::cout << std::setw(3) << (*v_iter).second
	      << " " << (*v_iter).first << std::endl;
  }

  return 0;
}
