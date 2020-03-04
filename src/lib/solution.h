#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;


//question 3: DFS graph without direction 

class Graph{
	public:
		Graph(map<int, set<int>> &vertices):v_(vertices) {}
		map<int, set<int>> v_;
    vector<int> DFS(Graph& g,int rt);
};


//question 4
class Graph4 {
public:
  vector<vector<int>> g4;
  Graph4(vector<vector<int> > &gr);
 
  void dfs(int rt, vector<int>& ret, vector<int> &vis);
  vector<int> DFS_ALL();
};


//question 5

class Maze {
public:
  Maze(vector<vector<int>> &graph): mazeg(graph){}

  int n; 
  vector<vector<int>> mazeg;
  int vis[100][100];
  
  bool inrange(int x, int y);
  void bfs(int x, int y);
};


//question 6: rearrange the vector 
class Sort {
public:
  void partition (vector<int> &input, int index, int low, int high);
};

#endif