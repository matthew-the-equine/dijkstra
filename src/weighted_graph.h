#include <map>
#include <iostream>
#include "singly_linked_list.h"
using namespace std;

template <typename V, typename W>
struct weighted_edge
{
  V from;
  V to;
  W weight;

  weighted_edge();
  weighted_edge(V, V, W);

  string to_string();
};

template <typename V, typename W>
weighted_edge<V, W>::weighted_edge()
{
}

template <typename V, typename W>
weighted_edge<V, W>::weighted_edge(V from, V to, W weight) : from(from), to(to), weight(weight)
{
}

template <typename V, typename W>
string weighted_edge<V, W>::to_string()
{
  stringstream ss;
  ss << from << " -> " << to << " : " << weight;
  return ss.str();
}

template <typename V, typename W>
class weighted_graph
{
private:
  map<V, singly_linked_list<weighted_edge<V, W> > > adjacents;

public:
  weighted_graph<V, W>();

  singly_linked_list<V> vertices();

  void add_vertex(V);
  void add_edge(weighted_edge<V, W>);
  
  singly_linked_list<weighted_edge<V, W> > adjacent(V);
};

template <typename V, typename W>
weighted_graph<V, W>::weighted_graph()
{
}

template <typename V, typename W>
singly_linked_list<V> weighted_graph<V, W>::vertices()
{
  singly_linked_list<V> vertices = singly_linked_list<V>();
  for (typename map<V, singly_linked_list<weighted_edge<V, W> > >::iterator it = adjacents.begin(); it != adjacents.end(); ++it)
  {
    vertices.push(it->first);
  }
  return vertices;
}

template <typename V, typename W>
void weighted_graph<V, W>::add_vertex(V vertex)
{
  adjacents[vertex] = singly_linked_list<weighted_edge<V, W> >();
}

template <typename V, typename W>
void weighted_graph<V, W>::add_edge(weighted_edge<V, W> edge)
{
  if (!adjacents.count(edge.from))
  {
    add_vertex(edge.from);
  }
  if (!adjacents.count(edge.to))
  {
    add_vertex(edge.to);
  }
  
  adjacents[edge.from].push(edge);
  adjacents[edge.to].push(edge);
}

template <typename V, typename W>
singly_linked_list<weighted_edge<V, W> > weighted_graph<V, W>::adjacent(V vertex)
{
  return adjacents[vertex];
}