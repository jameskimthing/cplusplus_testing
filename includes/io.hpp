#ifndef IO_HPP
#define IO_HPP

#include <fstream>
#include <iostream>
#include <string>

void ReadInputFile();
void WriteGradesFile();
void IoReadTerminal();

struct Student {
  std::string name;
  unsigned int uin;
  double gpa;
};

#endif