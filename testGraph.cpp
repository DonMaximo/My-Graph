#include <gtest/gtest.h>
#include "graph.hpp"

TEST(GraphTest, TestAddEdge) {
  Graph<int> g;
  g.add_edge(1, 2);
  g.add_edge(2, 3);
  g.add_edge(3, 4);

  // Check if the edges were added to the adjacency list
  EXPECT_EQ(g.adjacency_list[1].size(), 1);
  EXPECT_EQ(g.adjacency_list[2].size(), 2);
  EXPECT_EQ(g.adjacency_list[3].size(), 2);
  EXPECT_EQ(g.adjacency_list[4].size(), 1);

  // Check if the edges were added to the edges set
  EXPECT_EQ(g.get_edges().size(), 3);
}

TEST(GraphTest, TestBFS) {
  Graph<int> g;
  g.add_edge(1, 2);
  g.add_edge(1, 3);
  g.add_edge(2, 4);
  g.add_edge(3, 5);
  g.add_edge(4, 6);
  g.add_edge(5, 6);

  // Perform BFS starting from vertex 1
  std::string bfs_result = "1 2 3 4 5 6 ";
  testing::internal::CaptureStdout();
  g.BFS(1);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, bfs_result);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}