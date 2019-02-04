using namespace std;

template<typename T>
struct node
{
  T data;
  node<T> *next;
};

template <typename T>
class forward_iterator;

template<typename T>
class singly_linked_list
{
private:
  node<T> *head, *tail;

public:
  int size;

  singly_linked_list<T>();

  void push(T);

  forward_iterator<T> begin();
  forward_iterator<T> end();
};

template <typename T>
class forward_iterator
{
private:
  node<T> *ptr;

public:
  forward_iterator(node<T> *);

  T& operator*();
  forward_iterator &operator++();
  bool operator==(const forward_iterator &);
  bool operator!=(const forward_iterator &);
  forward_iterator &operator=(const forward_iterator &i);
};

template<typename T>
singly_linked_list<T>::singly_linked_list() : head(NULL), tail(NULL), size(0)
{
}

template<typename T>
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
  size++;
}

template <typename T>
forward_iterator<T> singly_linked_list<T>::begin()
{
  return forward_iterator<T>(head);
}

template <typename T>
forward_iterator<T> singly_linked_list<T>::end()
{
  return forward_iterator<T>(NULL);
}

template <typename T>
forward_iterator<T>::forward_iterator(node<T> *ptr) : ptr(ptr)
{
}

template <typename T>
T& forward_iterator<T>::operator*() { return ptr->data; }

template <typename T>
forward_iterator<T>& forward_iterator<T>::operator++()
{
  ptr = ptr->next;
  return *this;
}

template <typename T>
bool forward_iterator<T>::operator==(const forward_iterator &i)
{
  if (ptr == i.ptr)
    return true;

  return false;
}

template <typename T>
bool forward_iterator<T>::operator!=(const forward_iterator &i)
{
  return !(*this == i);
}

template <typename T>
forward_iterator<T>& forward_iterator<T>::operator=(const forward_iterator &i)
{
  ptr = i.ptr;

  return *this;
}