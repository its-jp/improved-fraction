#include "linked_list.hpp"
#include "stack.hpp"
#include <stdexcept>
#include <string>

template <typename T>
void Stack<T>::push(const T& data) {
  this->addNodeLast(new Node(data));
}

template <typename T>
T Stack<T>::pop() {
  Node<T>* node = this->popNodeLast();
  if(!node) throw std::runtime_error("Stack Underflow");
  T data = node->data;
  delete node;
}

template <typename T>
bool Stack<T>::isEmpty() const {
  return this->head == nullptr;
}

template <typename T>
std::string Stack<T>::toString() const {
  return LinkedList<T>::toString();
}
