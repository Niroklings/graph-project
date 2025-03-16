#include "Graph.h"
#include <cstdio>
#include <fstream>
#include <gtest/gtest.h>

std::string createTempGraphFile(const std::string &content) {
  std::string filename = "temp_graph.txt";
  std::ofstream outFile(filename);
  outFile << content;
  outFile.close();
  return filename;
}

TEST(GraphTest, ShortestPathCorrectness) {
  std::string graphData = "5\n"
                          "4\n"
                          "0 1\n"
                          "0 4\n"
                          "1 2\n"
                          "1 3\n"
                          "0\n";

  std::string filename = createTempGraphFile(graphData);

  Graph graph(filename);
  std::vector<int> distances = graph.shortestDistances();

  ASSERT_EQ(distances.size(), 5);

  EXPECT_EQ(distances[0], 0);
  EXPECT_EQ(distances[1], 1);
  EXPECT_EQ(distances[4], 1);
  EXPECT_EQ(distances[2], 2);
  EXPECT_EQ(distances[3], 2);

  std::remove(filename.c_str());
}

TEST(GraphTest, SingleVertexGraph) {
  std::string graphData = "1\n"
                          "0\n"
                          "0\n";

  std::string filename = createTempGraphFile(graphData);

  Graph graph(filename);
  std::vector<int> distances = graph.shortestDistances();

  ASSERT_EQ(distances.size(), 1);
  EXPECT_EQ(distances[0], 0);

  std::remove(filename.c_str());
}

TEST(GraphTest, InvalidFileFormat) {
  std::string graphData = "bad data\n";

  std::string filename = createTempGraphFile(graphData);

  EXPECT_ANY_THROW({ Graph graph(filename); });

  std::remove(filename.c_str());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
