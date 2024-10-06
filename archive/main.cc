#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <vector>

#include "cat.hpp"

int main() {
  // standard input output

  std::map<std::string, std::vector<std::string>> courses_taught = {
      {"Math", {"Calculus", "Algebra"}}, {"Science", {"Chemistry", "Physics"}}};
  // ...
  for (const auto& [key, value] : courses_taught) {
    std::cout << key + ": " << value[0] << std::endl;
  }

  std::string things[2] = {"thing 1", "thing 2"};
  std::cout << *things << std::endl;

  int num0 = 10;
  int& numCopy = num0;
  numCopy = 20;
  std::cout << num0 << std::endl;

  return 0;

  // Standard stujcts
  Cat myCat;
  myCat.name = "Mittens";
  myCat.age = 5;
  myCat.uin = 123456789;

  std::cout << "My cat's name is " + getNameOfCat(myCat) << std::endl
            << std::endl;
  // std::cout << "What's your cat's name?" << std::endl;

  // // Get your cat's name
  // std::string yourCatName;
  // std::cin >> yourCatName;

  // Cat yourCat = {yourCatName, 0, 0};
  // std::cout << "Your cat's name is " + getNameOfCat(yourCat) << std::endl <<
  // std::endl;

  int x = 0;
  int y = 1;
  x = y = 5;  // x gets 5, not 1.
  std::cout << "(associativity) The value of x is: " << x << std::endl
            << std::endl;
}