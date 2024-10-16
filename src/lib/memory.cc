#include "memory.hpp"

#include <iostream>

char* AllocateCharArray(int size) {
  std::cout << "AllocateCharArray of size " << size << "" << std::endl;
  char* array = new char[size];
  return array;
}

void FreeCharArray(char* array) {
  std::cout << "FreeCharArray" << std::endl;
  delete[] array;
}

void RunMemory() {
  char* array = AllocateCharArray(10);
  FreeCharArray(array);

  char* p_char = new char('a');
  std::cout << *p_char << std::endl;
  delete p_char;
}