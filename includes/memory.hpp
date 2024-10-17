#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <iostream>

// dynamic memory allocation
char* AllocateCharArray(int size);
void FreeCharArray(char* array);
void RunMemory();

#endif