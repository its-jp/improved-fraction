#include <catch2/catch_test_macros.hpp>
#include "linked_list.hpp"

TEST_CASE("Linked List - Insertion", "[linked_list]"){
  LinkedList<int> list;
  list.addNodeFirst(new Node(10));
  list.addNodeFirst(new Node(20));

  list.addNodeLast(new Node(40));
  Node<int>* node = list.popNodeLast();
  REQUIRE(node->data == 40);
  node = list.popNodeFirst();
  REQUIRE(node->data == 20);
}
