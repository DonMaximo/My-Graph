#include <iostream>
#include "graph.hpp"

void test_add_edge() {
    Graph<int> g;
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);

    // Check if the edges were added to the adjacency list
    if (g.adjacency_list[1].size() == 1 &&
        g.adjacency_list[2].size() == 2 &&
        g.adjacency_list[3].size() == 2 &&
        g.adjacency_list[4].size() == 1)
        std::cout << "test_add_edge: PASS" << std::endl;
    else
        std::cout << "test_add_edge: FAIL" << std::endl;
    // Check if the edges were added to the edges set
    if (g.get_edges().size() == 3)
        std::cout << "test_add_edge: PASS" << std::endl;
    else
        std::cout << "test_add_edge: FAIL" << std::endl;
}

void test_get_edges() {
    Graph<int> g;
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    std::unordered_set<std::pair<int,int>> edges = g.get_edges();
    bool all_edges_exist = true;
    for(auto edge : edges) {
        if(!g.adjacency_list.count(edge.first) || !g.adjacency_list[edge.first].count(edge.second)) {
            all_edges_exist = false;
            break;
        }
    }
    if (all_edges_exist)
        std::cout << "test_get_edges: PASS" << std::endl;
    else
        std::cout << "test_get_edges: FAIL" << std::endl;
}

void test_add_same_edge_twice() {
    Graph<int> g;
    g.add_edge(1, 2);
    g.add_edge(1, 2);
    if (g.adjacency_list[1].size() == 1 && g.get_edges().size() == 1)
        std::cout << "test_add_same_edge_twice: PASS" << std::endl;
    else
        std::cout << "test_add_same_edge_twice: FAIL" << std::endl;
}

void test_empty_graph() {
    Graph<int> g;
    if (g.adjacency_list.size() == 0 && g.get_edges().size() == 0)
        std::cout << "test_empty_graph: PASS" << std::endl;
    else
        std::cout << "test_empty_graph: FAIL" << std::endl;
}

void test_BFS() {
    Graph<int> g;
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 4);
    g.add_edge(3, 5);
    g.add_edge(4, 6);
    g.add_edge(5, 6);

    // Perform BFS starting from vertex 1
    std::string bfs_result = "1 2 3 4 5 6 ";
    std::string output = "";
    g.BFS(1,output);
    if (output == bfs_result)
        std::cout << "test_BFS: PASS" << std::endl;
    else
        std::cout << "test_BFS: FAIL" << std::endl;
}

int main() {
    test_add_edge();
    test_add_same_edge_twice();
    test_get_edges();
    test_empty_graph();
    test_BFS();
    return 0;
}
