#include <unordered_set>
#include <unordered_map>
#include <utility>

template <typename T>
class Graph {
  std::unordered_map<T, std::unordered_set<T>> adjacency_list;
  std::unordered_set<std::pair<T, T>> edges;

public:
  void add_edge(T u, T v) {
    adjacency_list[u].insert(v);
    adjacency_list[v].insert(u);
    edges.insert({u, v});
  }

  void print() {
    for (const auto& vertex : adjacency_list) {
      std::cout << vertex.first << ": ";
      for (const auto& neighbor : vertex.second) {
        std::cout << neighbor << " ";
      }
      std::cout << std::endl;
    }
  }

  void BFS(T start) {
    std::unordered_set<T> visited;
    std::queue<T> q;

    visited.insert(start);
    q.push(start);

    while (!q.empty()) {
      T current = q.front();
      q.pop();
      std::cout << current << " ";

      for (const auto& neighbor : adjacency_list[current]) {
        if (visited.find(neighbor) == visited.end()) {
          visited.insert(neighbor);
          q.push(neighbor);
        }
      }
    }
  }

  const std::unordered_set<std::pair<T, T>>& get_edges() { return edges; }
};
