#include <iostream>
#include "singly_linked_list.h"
using namespace std;

template<class T>
singly_linked_list<T>::singly_linked_list() : head(NULL), tail(NULL)
{
}

template<class T>
void singly_linked_list<T>::push(T value)
{
  node<T> *temp = new node<T>;
  temp->data = value;
  temp->next = NULL;

  if (head == NULL)
  {
    head = temp;
    tail = temp;
    temp = NULL;
  }
  else
  {
    tail->next = temp;
    tail = temp;
  }
}

template<class T>
void singly_linked_list<T>::display()
{
  node<T> *temp = new node<T>;
  temp = head;
  while (temp != NULL)
  {
    cout << temp->data << ",";
    temp = temp->next;
  }
}

// linker issues
template class singly_linked_list<int>;
