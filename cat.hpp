#ifndef CAT_HPP
#define CAT_HPP

#include <string>

struct Cat {
  std::string name;
  int age;
  unsigned int uin;
};

std::string getNameOfCat(Cat cat);

#endif