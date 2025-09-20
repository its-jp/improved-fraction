#include "linked_list.hpp"
#include "node.hpp"
#include <iostream>
#include <string>
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& l) : head(nullptr) {
  Node<T>* currentNode = l.head;
  while(currentNode != nullptr){
    this->addNodeLast(currentNode);
    currentNode = currentNode->next;
  }
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
Node<T>* LinkedList<T>::popNodeFirst(){
  if(this->head == nullptr) return nullptr;
  
  Node<T>* prevHead = this->head;
  this->head = this->head->next;

  return prevHead;
}

template <typename T>
void LinkedList<T>::removeNodeFirst(){
  if(this->head == nullptr) return;
  
  Node<T>* prevHead = this->head;
  this->head = this->head->next;

  delete prevHead;
}

template <typename T>
Node<T>* LinkedList<T>::popNodeLast(){
  if(this->head == nullptr) return nullptr;

  Node<T>* currentNode = this->head;  Node<T>* prevNode = nullptr;
  while(currentNode->next != nullptr){
    prevNode = currentNode;
    currentNode = currentNode->next;
  }
  //INFO: Checks if there is only the head as node!
  if(prevNode == nullptr){
    Node<T>* poppedNode = this->head;
    this->head = nullptr;
    return poppedNode;
  }
  prevNode->next = nullptr;
  return currentNode;
}

template <typename T>
void LinkedList<T>::removeNodeLast(){
  if(this->head == nullptr) return;

  Node<T>* currentNode = this->head;
  Node<T>* prevNode = nullptr;
  while(currentNode->next != nullptr){
    prevNode = currentNode;
    currentNode = currentNode->next;
  }
  //INFO: Checks if there is only the head as node!
  if(currentNode == nullptr){
    this->head = nullptr;
  }
  prevNode->next = nullptr;
  delete currentNode;
}

template <typename T>
std::string LinkedList<T>::toString() const {
  if(this->head == nullptr) return "";
  std::string result;
  int counter = 1;
  Node<T>* currentNode = this->head;
  while(currentNode != NULL){
    result += std::to_string(counter) + " : " + std::to_string(currentNode->data) + "\n";
    currentNode = currentNode->next;
  }
  return result;
}
