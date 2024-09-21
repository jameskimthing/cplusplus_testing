#include "io.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void ReadInputFile() {
  // assumes this file is within our working
  const std::string input_file_name("../data/input.txt");
  // directory
  std::ifstream ifs{input_file_name};
  if (!ifs.is_open()) {
    std::cerr << "Could not open " << input_file_name << std::endl;
    return;
  }

  std::string file_headers;
  std::getline(ifs, file_headers);  // discard first line
  // print file headers
  std::cout << file_headers << std::endl;

  while (ifs.good()) {
    unsigned int student_uin = 0;
    double student_gpa = 0.0;
    unsigned int student_midterm = 0;
    unsigned int student_final = 0;
    char throw_away = '\0';
    ifs >> student_uin >> throw_away >> student_gpa >> throw_away >>
        student_midterm >> throw_away >> student_final;
    // print error
    if (ifs.fail()) std::cout << "Error reading data" << std::endl;
    // break;
    // print
    std::cout << student_uin << " " << student_gpa << " " << student_midterm
              << " " << student_final << std::endl;
  }

  return;
}

void WriteGradesFile() {
  std::vector<Student> students;
  students.push_back(Student{"Jack", 1234, 3.23});
  students.push_back(Student{"Jill", 5678, 3.67});

  std::ofstream ofs("../data/grades.csv");
  ofs << "Name,UIN,GPA\n";
  for (unsigned int i = 0; i < students.size(); ++i) {
    ofs << students[i].name << ',' << students[i].uin << ',' << students[i].gpa
        << '\n';
  }
  return;
}

void IoReadTerminal() {
  std::cout << "Please a monetary value (as dollars.cents): $";

  int dollars = 0;
  char throw_away = '\0';
  int cents = 0;
  std::cin >> dollars >> throw_away >> cents;

  std::cout << "You entered " << dollars << " dollars and " << cents
            << " cents." << '\n';
}
