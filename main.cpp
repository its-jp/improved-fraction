#include "lib/fraction.hpp"
#include <iostream>
int main(){

  Fraction f1 = Fraction(9, 5);
  ++f1;
  --f1;
  std::cout << f1.toString() << "\n";
  return 0;
}
