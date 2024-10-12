#include "generic_class.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

void RunGenericClass() {
  GenericClass gc = GenericClass(7);
  std::cout << "a: " << gc.a() << std::endl;
  std::cout << "b: " << gc.b() << std::endl;
  std::cout << "c: " << gc.c() << std::endl;
  gc.a(8);
  gc.b(9);
  gc.c(10);
  std::cout << "a: " << gc.a() << std::endl;
  std::cout << "b: " << gc.b() << std::endl;
  std::cout << "c: " << gc.c() << std::endl;

  // Prepend them all to a string
  std::string str = "";
  str += "a: ";
  str += std::to_string(gc.a());
  str += ", b: ";
  str += std::to_string(gc.b());
  str += ", c: ";
  str += std::to_string(gc.c());
  std::cout << str << std::endl;

  // operator
  GenericClass gc2 = gc;
  std::cout << "a: " << gc2.a() << std::endl;
  std::cout << "b: " << gc2.b() << std::endl;
  std::cout << "c: " << gc2.c() << std::endl;
  if (gc == gc2) std::cout << "gc == gc2" << std::endl;

  // operator ostream
  std::cout << "gc:" << gc << std::endl;
}

// Constructors and Destructors
// GenericClass::GenericClass(): b_(0)
//      -> using {} gives errors if value does not match type of b -> prevents
//      narrowing conversions
//      -> using () does not give errors if value does not match type of b
GenericClass::GenericClass(): b_{0} {
  std::cout << "Initialized b_ to 0, and a_ is " << a_ << "" << std::endl;
}
GenericClass::GenericClass(int c): a_{c}, b_{0} {
  c_ = c;
  std::cout << "Initialized b_ to 0, set c_ to " << c_ << ", and a_ is " << a_
            << "(overrided default in-class initializer)" << std::endl;
}
GenericClass::~GenericClass() {
  std::cout << "GenericClass::~GenericClass()" << std::endl;
}

// Getters and setters
int GenericClass::a() const { return a_; }
int GenericClass::b() const { return b_; }
int GenericClass::c() const { return c_; }
void GenericClass::a(int new_a) {
  if (!ValidABC(new_a)) throw std::runtime_error("Invalid value");
  a_ = new_a;
}
void GenericClass::b(int new_b) {
  if (!ValidABC(new_b)) throw std::runtime_error("Invalid value");
  b_ = new_b;
}
void GenericClass::c(int new_c) {
  if (!ValidABC(new_c)) throw std::runtime_error("Invalid value");
  c_ = new_c;
}
bool GenericClass::ValidABC(int val) {
  if (val < 0 || val > 100) return false;
  return true;
}

/*
Member or nonmember implementation?
We must decide whether to define an overloaded operator as a class member or a
nonmember function
 - Some operators are required to be members; others may not be able to be
   correctly defined as such
When overloading an operator, you should follow these guidelines:
 - Assignment (=), subscript([ ]), call (( )), and member access arrow (->) must
be defined as members
 - Compound assignment operators (ex., +=) should be defined as members
 - Operators that change the state of an object should be defined as members
 - Symmetric operators should be defined as non-members
    - We want to use symmetric operators in expressions with mixed types
*/

std::ostream& operator<<(std::ostream& os, const GenericClass& gc) {
  os << "a: " << gc.a() << ", b: " << gc.b() << ", c: " << gc.c();
  return os;
}

// OPERATORS
bool GenericClass::operator==(const GenericClass& other) const {
  return (a_ == other.a_ && b_ == other.b_ && c_ == other.c_);
}

// Using "this"
// bool GenericClass::operator==(const GenericClass& other) const {
//   return (this->a_ == other.a_ && this->b_ == other.b_ && this->c_ ==
//   other.c_);
// }

// Definition of the non-member operator== function
// bool operator==(const GenericClass& a1, const GenericClass& a2) {
//     return (a1.a() == a2.a() && a1.b() == a2.b() && a1.c() == a2.c());
// }
