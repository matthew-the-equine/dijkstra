#include <iostream>
using namespace std;

template<typename T>
struct node
{
  T data;
  node<T> *next;
};

template<typename T>
class singly_linked_list
{
private:
  node<T> *head, *tail;

public:
  singly_linked_list<T>();

  void push(T);
  void display();
};

