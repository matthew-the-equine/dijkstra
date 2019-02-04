
using namespace std;

template<typename T>
class index_min_priority_queue
{
private:
  int max_N;
  int n;
  int* pq;
  int* qp;
  T* keys;

  void swim(int k);
  void sink(int k);

  bool greater(int i, int j);
  void exch(int i, int j);

public:
  index_min_priority_queue(int);

  bool contains(int i);
  bool is_empty();

  void insert(int i, T key);
  void changeKey(int i, T key);

  int del_min();
};

template<typename T>
index_min_priority_queue<T>::index_min_priority_queue(int max_N) :
  max_N(max_N),
  n(0)
{
  pq = new int[max_N + 1];
  qp = new int[max_N + 1];
  keys = new T[max_N + 1];
  for (int i = 0; i <= max_N; i++)
    qp[i] = -1;
}

template<typename T>
bool index_min_priority_queue<T>::is_empty()
{
  return n == 0;
}

template<typename T>
bool index_min_priority_queue<T>::contains(int i) 
{
  if (i < 0 || i >= max_N) 
    return false;
  return qp[i] != -1;
}

template<typename T>
void index_min_priority_queue<T>::insert(int i, T key) 
{
  if (i < 0 || i >= max_N || contains(i)) 
    return;

  n++;
  qp[i] = n;
  pq[n] = i;
  keys[i] = key;
  swim(n);
}

template<typename T>
void index_min_priority_queue<T>::changeKey(int i, T key) 
{
  if (i < 0 || i >= max_N || !contains(i)) 
    return;
  keys[i] = key;
  swim(qp[i]);
  sink(qp[i]);
}

template<typename T>
int index_min_priority_queue<T>::del_min() 
{
  int min = pq[1];
  exch(1, n--);
  sink(1);
  qp[min] = -1;        
  pq[n+1] = -1;        
  return min;
}

template<typename T>
void index_min_priority_queue<T>::swim(int k) 
{
  while (k > 1 && greater(k/2, k)) 
  {
    exch(k, k/2);
    k = k/2;
  }
}

template<typename T>
void index_min_priority_queue<T>::sink(int k) 
{
  while (2*k <= n) 
  { 
    int j = 2*k;
    if (j < n && greater(j, j+1)) j++;
    if (!greater(k, j)) break;
    exch(k, j);
    k = j;
  }
}

template<typename T>
bool index_min_priority_queue<T>::greater(int i, int j) 
{
  return keys[pq[i]] > keys[pq[j]];
}

template<typename T>
void index_min_priority_queue<T>::exch(int i, int j) 
{
  int swap = pq[i];
  pq[i] = pq[j];
  pq[j] = swap;
  qp[pq[i]] = i;
  qp[pq[j]] = j;
}