#include <iostream>
#include <string>

#include "general_concepts.hpp"
#include "io.hpp"

int main(int argc, const char* argv[]) {
  if (argc != 3) {
    std::cout << "Invalid argument. Pls try again" << std::endl;
    return -1;
  }

  const std::string type = argv[1];
  if (type == "gc") {
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
  } else if (type == "io") {
    const std::string f = argv[2];
    if (f == "readfile")
      ReadInputFile();
    else if (f == "writefile")
      WriteGradesFile();
    else if (f == "readterminal")
      IoReadTerminal();
    else
      std::cout << "Invalid argument" << std::endl;
  } else {
    std::cout << "Invalid argument. Pls try again" << std::endl;
  }
}