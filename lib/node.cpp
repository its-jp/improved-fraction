#include "node.hpp"
#include <malloc/_malloc.h>
Node::Node(size_t t){
  this->data = malloc(t);
  this->next = nullptr;
}
