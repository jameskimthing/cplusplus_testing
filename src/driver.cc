#include <iostream>
#include <string>

#include "general_concepts.hpp"

int main(int argc, const char* argv[]) {
  if (argc == 1 || argc > 3) return -1;

  if (argv[1] == "gc") {
    const std::string d = argv[2];
    char dir = 'N';
    double val = 5.5;

    if (d == "vector")
      GCVectors();
    else if (d == "forloop")
      GCForLoops();
    else if (d == "switch")
      GCSwitch(dir);
    else if (d == "limits")
      GCLimits();
    else if (d == "sets")
      GCSets();
    else if (d == "maps")
      GCMaps();
    else if (d == "staticcast")
      GCStaticCast(val);
    else
      std::cout << "Invalid argument" << std::endl;
  } else if (argv[1] == "io") {
    const std::string f = argv[2];
  }
}