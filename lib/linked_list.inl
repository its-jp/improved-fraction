#include "linked_list.hpp"
#include "node.hpp"
#include <iostream>
#include <string>
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& l) {

}

template <typename T>
void LinkedList<T>::addNodeFirst(Node<T>* node){
  if(node == nullptr) return;
  // if(this->head == nullptr) { //NOTE: there is no need for adding this if since the part below already would already work without this if!
  // 
  //   this->head = node;
  //   return;
  // }
  Node<T>* prevHead = this->head;
  this->head = node;
  this->head->next = prevHead;
}

template <typename T>
void LinkedList<T>::addNodeLast(Node<T>* node){
  if(node == nullptr) return;
  Node<T>* currentNode = this->head;
  Node<T>* prevNode = nullptr;
  while(currentNode != NULL){
    prevNode = currentNode;
    currentNode = currentNode->next;
  }
  if(prevNode == nullptr) {
    this->addNodeFirst(node);
    return;
  }
  prevNode->next = node;
}


template <typename T>
std::string LinkedList<T>::toString() {
  if(this->head == nullptr) return NULL;
  std::string result;
  int counter = 1;
  Node<T>* currentNode = this->head;
  while(currentNode != NULL){
    result += std::to_string(counter) + " : " + std::to_string(currentNode->data) + "\n";
    currentNode = currentNode->next;
  }
  return result;
}
