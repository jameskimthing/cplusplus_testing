#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <fstream>

#include "cat.hpp"
#include "cat.cc"
struct Student
{
    std::string name;
    unsigned int uin;
    double gpa;
};
int main()
{
    // std::vector<Student> students;
    // students.push_back(Student{"Jack", 1234, 3.23});
    // students.push_back(Student{"Jill", 5678, 3.67});

    // std::ofstream ofs("./grades.csv");
    // ofs << "Name,UIN,GPA\n";
    // for (unsigned int i = 0; i < students.size(); ++i)
    // {
    //     ofs << students[i].name << ',' << students[i].uin << ',' << students[i].gpa << '\n';
    // }

    // return 0;

    const std::string input_file_name("./input.txt"); // assumes this file is within our working directory
    std::ifstream ifs{input_file_name};
    if (!ifs.is_open())
    {
        std::cerr << "Could not open " << input_file_name << std::endl;
        return 1;
    }

    std::string file_headers;
    std::getline(ifs, file_headers); // discard first line
    // print file headers
    std::cout << file_headers << std::endl;

    while (ifs.good())
    {
        unsigned int student_uin = 0;
        double student_gpa = 0.0;
        unsigned int student_midterm = 0;
        unsigned int student_final = 0;
        char throw_away = '\0';
        ifs >> student_uin >> throw_away >> student_gpa >> throw_away >> student_midterm >> throw_away >> student_final;
        if (ifs.fail())
            // print error
            std::cout << "Error reading data" << std::endl;
        // break;
        // print
        std::cout << student_uin << " " << student_gpa << " " << student_midterm << " " << student_final << std::endl;

        // do something with the data
    }

    return 0;

    // standard input output
    std::cout << "Please a monetary value (as dollars.cents): $";

    int dollars = 0;
    char throw_away = '\0';
    int cents = 0;
    std::cin >> dollars >> throw_away >> cents;

    std::cout << "You entered " << dollars << " dollars and " << cents << " cents." << '\n';

    return 0;

    std::map<std::string, std::vector<std::string>> courses_taught = {
        {"Math", {"Calculus", "Algebra"}},
        {"Science", {"Chemistry", "Physics"}}};
    // ...
    for (const auto &[key, value] : courses_taught)
    {
        std::cout << key + ": " << value[0] << std::endl;
    }

    std::string things[2] = {"thing 1", "thing 2"};
    std::cout << *things << std::endl;

    int num0 = 10;
    int &numCopy = num0;
    numCopy = 20;
    std::cout << num0 << std::endl;

    return 0;

    // Standard stujcts
    Cat myCat;
    myCat.name = "Mittens";
    myCat.age = 5;
    myCat.uin = 123456789;

    std::cout << "My cat's name is " + getNameOfCat(myCat) << std::endl
              << std::endl;
    // std::cout << "What's your cat's name?" << std::endl;

    // // Get your cat's name
    // std::string yourCatName;
    // std::cin >> yourCatName;

    // Cat yourCat = {yourCatName, 0, 0};
    // std::cout << "Your cat's name is " + getNameOfCat(yourCat) << std::endl << std::endl;

    // Limits
    std::cout << "Max value of signed int: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Minimum value of signed int: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Max value of unsigned int: " << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << "Minimum value of unsigned int: " << std::numeric_limits<unsigned int>::min() << std::endl
              << std::endl;

    double largeNumber = 1.5E25;
    std::cout << "The value of largeNumber is: " << largeNumber << std::endl
              << std::endl;

    // static cast
    std::cout << "(casting) The value of int is: " << static_cast<int>(5 * 0.1) << std::endl
              << std::endl;

    int x = 0;
    int y = 1;
    x = y = 5; // x gets 5, not 1.
    std::cout << "(associativity) The value of x is: " << x << std::endl
              << std::endl;

    // Switch cases
    char direction = 'N';
    std::cout << "You are heading ";
    switch (direction)
    {
    case 'N':
    {
        std::cout << "North";
        break;
    }
    case 'E':
    {
        std::cout << "East";
        break;
    }
    case 'S':
    {
        std::cout << "South";
        break;
    }
    case 'W':
    {
        std::cout << "West";
        break;
    }
    default:
    {
        std::cout << "in an unknown direction";
        break;
    }
    }

    std::cout << std::endl;

    // For loops
    std::cout << "For loops: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Vectors
    std::cout << "Vectors: ";
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}