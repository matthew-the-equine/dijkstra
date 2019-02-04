#include <cstdio>

class MinIndexedPQ
{
  int NMAX, N, *heap, *index, *keys;

  void swap(int i, int j)
  {
    int t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
    index[heap[i]] = i;
    index[heap[j]] = j;
  }

  void bubbleUp(int k)
  {
    while (k > 1 && keys[heap[k / 2]] > keys[heap[k]])
    {
      swap(k, k / 2);
      k = k / 2;
    }
  }

  void bubbleDown(int k)
  {
    int j;
    while (2 * k <= N)
    {
      j = 2 * k;
      if (j < N && keys[heap[j]] > keys[heap[j + 1]])
        j++;
      if (keys[heap[k]] <= keys[heap[j]])
        break;
      swap(k, j);
      k = j;
    }
  }

public:
  MinIndexedPQ(int NMAX)
  {
    this->NMAX = NMAX;
    N = 0;
    keys = new int[NMAX + 1];
    heap = new int[NMAX + 1];
    index = new int[NMAX + 1];
    for (int i = 0; i <= NMAX; i++)
      index[i] = -1;
  }

  ~MinIndexedPQ()
  {
    delete[] keys;
    delete[] heap;
    delete[] index;
  }

  bool isEmpty()
  {
    return N == 0;
  }

  bool contains(int i)
  {
    return index[i] != -1;
  }

  int size()
  {
    return N;
  }

  void insert(int i, int key)
  {
    N++;
    index[i] = N;
    heap[N] = i;
    keys[i] = key;
    bubbleUp(N);
  }

  int minIndex()
  {
    return heap[1];
  }

  int minKey()
  {
    return keys[heap[1]];
  }

  int deleteMin()
  {
    int min = heap[1];
    swap(1, N--);
    bubbleDown(1);
    index[min] = -1;
    heap[N + 1] = -1;
    return min;
  }

  int keyOf(int i)
  {
    return keys[i];
  }

  void changeKey(int i, int key)
  {
    keys[i] = key;
    bubbleUp(index[i]);
    bubbleDown(index[i]);
  }

  void decreaseKey(int i, int key)
  {
    keys[i] = key;
    bubbleUp(index[i]);
  }

  void increaseKey(int i, int key)
  {
    keys[i] = key;
    bubbleDown(index[i]);
  }

  void deleteKey(int i)
  {
    int ind = index[i];
    swap(ind, N--);
    bubbleUp(ind);
    bubbleDown(ind);
    index[i] = -1;
  }
};