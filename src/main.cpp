#include <iostream>
#include "singly_linked_list.h"
using namespace std;

int main() {
  singly_linked_list<int> a = singly_linked_list<int>();
  a.push(1);
  a.push(30);
  a.push(-1);
  a.display();
}