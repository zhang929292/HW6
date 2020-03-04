#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(q3Should, q3Return) {
  map<int, set<int>> vertices{
    {0, {1, 2, 5}},
		{1, {0, 2, 3}},
		{2, {0, 1, 3}},
		{3, {1, 2, 4, 6}},
		{4, {3}},
		{5, {0}},
    {6, {3}}
	};
    
	Graph g(vertices);
	int rt = 1;
  vector<int> actual = g.DFS(g, rt);
  vector<int> expected = {0, 1, 2, 3, 4, 6, 5};
  EXPECT_EQ(expected, actual);
}


TEST(q4Should, Returnq4) {
  vector<vector<int>> g4;
  int edges = 8;
  g4.resize(7);
  while (edges--){
        g4[0] = vector<int>({1});
	      g4[1] = vector<int>({2, 3});
        g4[2] = vector<int>({0});
        g4[3] = vector<int>({2, 4, 6});
        g4[4] = vector<int>({ });
        g4[5] = vector<int>({6});
        g4[6] = vector<int>({ });
	}
  Graph4 graph4(g4);
  vector<int> actual = graph4.DFS_ALL();
  vector<int> expected = {0, 1, 2, 3, 4, 6, 5};
  EXPECT_EQ(expected, actual);
}

TEST(q4nullShould, Returnq4null) {
  vector<vector<int>> g4;
  int edges = 8;
  g4.resize(0);
  while (edges--){
	}
  Graph4 graph4(g4);
  vector<int> actual = graph4.DFS_ALL();
  vector<int> expected = { };
  EXPECT_EQ(expected, actual);
}

TEST(q5Should, Returnq5) {
  vector<vector<int>> mazeg = {{1, 1, 0, 0, 0}, {1, 0, 1, 1, 1}, {1, 1, 0, 0, 1}, {1, 1, 0, 0, 1}, {1, 1, 1, 1, 1}};
	Maze maze(mazeg);
	int vis[5][5];
	int sx, sy, ex, ey;
	sx = sy = 0;
  ex = ey = 3;
	maze.bfs(sx, sy);
  bool actual = vis[ex][ey] == 1;
  bool expected = false;
  EXPECT_EQ(expected, actual);
}


TEST(Shouldq6, Returnq6) {
  Sort sort;
  vector<int> input = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
  sort.partition(input, 9, 0, 9);
  vector<int> actual = input;
  vector<int> expected = {5, 2, 3, 6, 12, 7, 14, 9, 11, 10 };
  EXPECT_EQ(expected, actual);
}