#ifndef GENERIC_CLASS
#define GENERIC_CLASS

#include <iostream>

class GenericClass {
public:
  //   GenericClass() = default;  // tells compiler to generate empty if not
  //   defined.
  // in this case, it is defined, so it is useless

  GenericClass();
  GenericClass(int new_c);
  ~GenericClass();

  // Getters and setters
  int a();
  int b();
  int c();
  void a(int new_a);
  void b(int new_b);
  void c(int new_c);

private:
  bool ValidABC(int val);

  // true initialization. This does not need to be in the constructor
  // initialization list, as it is defined here. Can treat this like
  // a_{7} is in all the constructor's initialization lists
  int a_ = 7;
  int b_;  // initialized in the constructor, so is same as a_
  int c_;  // initialized here, assigned in the constructor. Can be wrong
           // initial value
};

void RunGenericClass();

#endif