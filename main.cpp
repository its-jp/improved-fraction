#include "lib/fraction.hpp"
#include "lib/linked_list.hpp"
#include <cstdint>
#include <iostream>
int main(){

  Fraction f1 = Fraction(9, 5);
  Fraction f2 = Fraction(4, 8);
  Fraction f3 = Fraction(8, 8);
  Fraction f4 = Fraction(-8, 8);

  LinkedList l = LinkedList(sizeof(int));
  ++f1;
  --f1;
  Fraction::simplify(f2);
  Fraction::simplify(f3);
  Fraction::simplify(f4);
  std::cout << f1.toString() << "\n";
  std::cout << (f1++).toString() << "\n";
  std::cout << f1.toString() << "\n";
  std::cout << f2.toString() << "\n";
  std::cout << f3.toString() << "\n";
  std::cout << f4.toString() << "\n";

  std::cout << "=====COMPARACAO=====" << "\n";
  std::cout << (f2 < f3) << "\n"; //true
  std::cout << (f4 > f2) << "\n"; //false
  std::cout << (f4==f4) << "\n"; //true
  std::cout << (f4 != f3) << "\n"; //true
  return 0;
}
