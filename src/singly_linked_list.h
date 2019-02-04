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
  void iterate(void (*func)(T));
};

template<typename T>
singly_linked_list<T>::singly_linked_list() : head(NULL), tail(NULL)
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
}

template<typename T>
void singly_linked_list<T>::iterate(void (*func)(T))
{
  node<T> *temp = new node<T>;
  temp = head;
  while (temp != NULL)
  {
    func(temp->data);
    temp = temp->next;
  };
}