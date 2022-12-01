#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

// file: input.txt
// 68787 <- part1
void partOne(std::string filename)
{
  if(not std::filesystem::exists(filename))
  {
    std::cout << "the file does not exists!";
    return;
  }
  std::string line;
  std::fstream file(filename);
  int max = 0;
  int total = 0;
  while(std::getline(file, line)) {
    // Account for CRLF if required
    line.erase(std::remove_if(std::begin(line), std::end(line), [](auto c) { return !isprint(c); }), std::end(line));
    if (line.size() == 0) {
      max = std::max(max, total);
      total = 0;
    } else {
      total += std::stoi(line);
    }
  }
  max = std::max(max, total);
  std::cout << max << '\n';
}

// 198041 <- part2
void partTwo(std::string filename)
{
  if(not std::filesystem::exists(filename))
  {
    std::cout << "the file does not exists!";
    return;
  }
  std::string line;
  std::fstream file(filename);

  std::vector<int> totals(1, 0);
  while(std::getline(file, line)) {
    line.erase(std::remove_if(std::begin(line), std::end(line), [](auto c) { return !isprint(c); }), std::end(line));
    if (line.size() == 0) {
      totals.emplace_back(0);
    } else {
      totals.back() += std::stoi(line);
    }
  }

  std::nth_element(std::begin(totals), std::begin(totals) + 3, std::end(totals), std::greater<int>());
  const auto sum = totals[0] + totals[1] + totals[2];
  std::cout << sum << '\n';
}

int main()
{
  partOne("input/input.txt");
  partTwo("input/input.txt");
}