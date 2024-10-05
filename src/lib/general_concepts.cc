#include "general_concepts.hpp"

#include <cassert>
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
  std::set<int> number_set = {5, 2, 8, 1, 9, 5};  // Note: 5 is repeated

  std::cout << "Elements in the set: ";
  for (const auto& elem : number_set) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  number_set.insert(3);
  std::cout << "After inserting 3: ";
  for (const auto& elem : number_set) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  if (number_set.find(8) != number_set.end()) {
    std::cout << "8 is in the set" << std::endl;
  }

  number_set.erase(2);
  std::cout << "After removing 2: ";
  for (const auto& elem : number_set) {
    std::cout << elem << " ";
  }
  std::cout << std::endl << std::endl;
}
void GCMaps() {
  std::cout << "Maps: " << std::endl;
  std::map<std::string, int> age_map = {
      {"Alice", 25}, {"Bob", 30}, {"Charlie", 35}};

  std::cout << "Ages in the map:" << std::endl;
  for (const auto& pair : age_map) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }

  age_map["David"] = 40;
  std::cout << "After adding David:" << std::endl;
  for (const auto& pair : age_map) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }

  if (age_map.find("Bob") != age_map.end()) {
    std::cout << "Bob's age is " << age_map["Bob"] << std::endl;
  }

  age_map.erase("Alice");
  std::cout << "After removing Alice:" << std::endl;
  for (const auto& pair : age_map) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }
  std::cout << std::endl;
}

void GCTryCatch() {
  std::cout << "Try/Catch: " << std::endl;
  // try {
  //   throw 5;
  // } catch (int e) {
  //   std::cout << "Caught an int: " << e << std::endl;
  // }

  try {
    throw std::runtime_error("This is a runtime error");
  } catch (const std::exception& e) {
    std::cout << "Caught an exception: " << e.what() << std::endl;
  }
}

void GCAssert() {
  std::cout << "Assert: " << std::endl;
  assert(5 == 5);
  assert(5 == 6);
}

void GCPointers() {
  std::cout << "Pointers: " << std::endl;
  int i = 7;
  int* ptr = &i;
  *ptr = 8;

  std::cout << &ptr << ' ' << ptr << ' ' << *ptr << ' ' << i << std::endl;
}

void GCArrays() {
  std::cout << "Arrays: " << std::endl;
  int arr[5] = {1, 2, 3, 4, 5};
  std::cout << (sizeof(arr) / sizeof(*arr)) << ' ' << arr[2] << ' ' << arr[4]
            << std::endl;

  // Pointer arithmetic,
  std::cout << *(arr + 0) << ' ' << *(arr + 2) << ' ' << *(arr + 4)
            << std::endl;
}