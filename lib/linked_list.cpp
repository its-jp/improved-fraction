#include "linked_list.hpp"
#include <cstddef>
#include <malloc/_malloc.h>
#include <iostream>
#include <string>

//TODO: add the copy constructor after everything is done!
LinkedList::LinkedList(size_t t) {
  this->data_type = t;
  this->head = nullptr;
}


void LinkedList::addNodeFirst(Node* node){
  if(this->head == nullptr){
    this->head = new Node(this->data_type);
    this->head = node;
    return;
  } 
  Node* currentNode = this->head;
  Node* prevNode = NULL;
  while(currentNode != NULL){
    prevNode = currentNode;
    currentNode = currentNode->next;
  }
}


std::string LinkedList::toString(){
  std::string result;
  Node* currentNode = this->head;
  int counter = 1;
  while(currentNode == NULL){
    //FIX: find a way to to_string an unknown type!
    result += std::to_string(counter) + " : " + std::to_string(*(currentNode->data));
    currentNode = currentNode->next;
  }
}
