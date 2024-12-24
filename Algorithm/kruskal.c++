#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
  int src, dest, weight;
};

// Compare edges by weight
bool compareEdge(Edge a, Edge b)
{
  return a.weight < b.weight;
}

// Find root
int findRoot(vector<int> &parent, int node)
{
  if (parent[node] != node)
    parent[node] = findRoot(parent, parent[node]);
  return parent[node];
}

// Union of two sets
void unionSets(vector<int> &parent, vector<int> &rank, int u, int v)
{
  int rootU = findRoot(parent, u);
  int rootV = findRoot(parent, v);

  if (rank[rootU] < rank[rootV])
    parent[rootU] = rootV;
  else if (rank[rootU] > rank[rootV])
    parent[rootV] = rootU;
  else
  {
    parent[rootV] = rootU;
    rank[rootU]++;
  }
}

// Kruskal's algorithm
void kruskalMST(vector<Edge> &edges, int V)
{
  sort(edges.begin(), edges.end(), compareEdge);

  vector<int> parent(V);
  vector<int> rank(V, 0);
  for (int i = 0; i < V; i++)
    parent[i] = i;

  vector<Edge> mst; // To store the result

  for (Edge edge : edges)
  {
    int rootU = findRoot(parent, edge.src);
    int rootV = findRoot(parent, edge.dest);

    if (rootU != rootV)
    {
      mst.push_back(edge);
      unionSets(parent, rank, rootU, rootV);
    }
  }

  cout << "The Edges in MST:\n";
  for (Edge e : mst)
    cout << e.src << " - " << e.dest << " (Weight : " << e.weight << ")\n";
}

int main()
{
  int V = 5;
  vector<Edge> edges = {
      {0, 1, 15}, {1, 2, 7}, {2, 3, 10}, {3, 4, 8}, {0, 4, 12}};

  kruskalMST(edges, V);

  return 0;
}
