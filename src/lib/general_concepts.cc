#include "general_concepts.hpp"

#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <vector>

void GCVectors() {
  std::cout << "Vectors: ";
  std::vector<int> numbers = {1, 2, 3, 4, 5};
  for (unsigned long int i = 0; i < numbers.size(); i++) {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;
}
void GCVectors(const std::vector<int>& vec) {
  for (unsigned long int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
}
void GCForLoops() {
  std::cout << "For loops: ";
  for (int i = 0; i < 5; i++) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
void GCSwitch(char& direction) {
  std::cout << "You are heading ";
  switch (direction) {
  case 'N': {
    std::cout << "North";
    break;
  }
  case 'E': {
    std::cout << "East";
    break;
  }
  case 'S': {
    std::cout << "South";
    break;
  }
  case 'W': {
    std::cout << "West";
    break;
  }
  default: {
    std::cout << "in an unknown direction";
    break;
  }
  }
}
void GCLimits() {
  std::cout << "Max value of signed int: " << std::numeric_limits<int>::max()
            << std::endl;
  std::cout << "Minimum value of signed int: "
            << std::numeric_limits<int>::min() << std::endl;
  std::cout << "Max value of unsigned int: "
            << std::numeric_limits<unsigned int>::max() << std::endl;
  std::cout << "Minimum value of unsigned int: "
            << std::numeric_limits<unsigned int>::min() << std::endl
            << std::endl;

  double largeNumber = 1.5E25;
  std::cout << "The value of largeNumber is: " << largeNumber << std::endl
            << std::endl;
}
void GCStaticCast(double& val) {
  std::cout << "(casting) The value of int is: " << static_cast<int>(val)
            << std::endl
            << std::endl;
}
void GCSets() {
  std::cout << "Sets: " << std::endl;
  std::set<int> numberSet = {5, 2, 8, 1, 9, 5};  // Note: 5 is repeated

  std::cout << "Elements in the set: ";
  for (const auto& elem : numberSet) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  numberSet.insert(3);
  std::cout << "After inserting 3: ";
  for (const auto& elem : numberSet) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  if (numberSet.find(8) != numberSet.end()) {
    std::cout << "8 is in the set" << std::endl;
  }

  numberSet.erase(2);
  std::cout << "After removing 2: ";
  for (const auto& elem : numberSet) {
    std::cout << elem << " ";
  }
  std::cout << std::endl << std::endl;
}
void GCMaps() {
  std::cout << "Maps: " << std::endl;
  std::map<std::string, int> ageMap = {
      {"Alice", 25}, {"Bob", 30}, {"Charlie", 35}};

  std::cout << "Ages in the map:" << std::endl;
  for (const auto& pair : ageMap) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }

  ageMap["David"] = 40;
  std::cout << "After adding David:" << std::endl;
  for (const auto& pair : ageMap) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }

  if (ageMap.find("Bob") != ageMap.end()) {
    std::cout << "Bob's age is " << ageMap["Bob"] << std::endl;
  }

  ageMap.erase("Alice");
  std::cout << "After removing Alice:" << std::endl;
  for (const auto& pair : ageMap) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }
  std::cout << std::endl;
}
