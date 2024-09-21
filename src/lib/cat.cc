#include "cat.hpp"

#include <string>

std::string getNameOfCat(Cat cat) {
  const std::string name = cat.name;
  return name;
}