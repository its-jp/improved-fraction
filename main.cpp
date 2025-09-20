#include "lib/fraction.hpp"
#include "lib/linked_list.hpp"
#include "lib/queue.hpp"
#include "lib/stack.hpp"
#include <iostream>
int main(){

  Fraction f1 = Fraction(9, 5);
  Fraction f2 = Fraction(4, 8);
  Fraction f3 = Fraction(8, 8);
  Fraction f4 = Fraction(-8, 8);

  LinkedList l = LinkedList<int>();
  Queue q = Queue<int>();
  q.enqueue(3);
  q.enqueue(5);
  q.enqueue(9);
  l.addNodeFirst(new Node<int>(3));
  l.addNodeLast(new Node<int>(5));
  l.addNodeFirst(new Node<int>(9));
  // ++f1;
  // --f1;
  // Fraction::simplify(f2);
  // Fraction::simplify(f3);
  // Fraction::simplify(f4);
  // std::cout << f1.toString() << "\n";
  // std::cout << (f1++).toString() << "\n";
  // std::cout << f1.toString() << "\n";
  // std::cout << f2.toString() << "\n";
  // std::cout << f3.toString() << "\n";
  // std::cout << f4.toString() << "\n";
  //
  // std::cout << "=====COMPARACAO=====" << "\n";
  // std::cout << (f2 < f3) << "\n"; //true
  // std::cout << (f4 > f2) << "\n"; //false
  // std::cout << (f4==f4) << "\n"; //true
  // std::cout << (f4 != f3) << "\n"; //true
  //
  // std::cout << "=====LISTA-LIGADA-TESTE=====" << "\n";
  // std::cout << "=====TESTE-ADD=====" << "\n";
  // std::cout << l.toString() << "\n";
  //
  //
  // l.removeNodeFirst();
  // l.removeNodeLast();
  // std::cout << "=====TESTE-REMOVE=====" << "\n";
  // std::cout << l.toString() << "\n";
  //
  std::cout << "=====QUEUE-TEST=====" << "\n";
  std::cout << q.toString() << "\n";

  std::cout << "=====TESTE-REMOVE=====" << "\n";
  q.dequeue();
  q.dequeue();
  std::cout << q.toString() << "\n";
  return 0;

}
