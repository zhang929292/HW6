#include "solution.h"


//question3: DFS graph without direction 
vector<int> Graph::DFS(Graph& g,int rt){
  vector<int> ret;
	map<int, int> vis;
	typedef pair<int, std::set<int>::iterator>  pir;
	stack<pir> stk;
	stk.push(pir(rt, g.v_[rt].begin() ));
	vis[rt] = 0;

	while (!stk.empty()){
		auto T = stk.top(); stk.pop();
		int nxt = *T.second;

		T.second++;
		if (T.second != g.v_[T.first].end())
			stk.push(T);

		if (vis[nxt] == 0){
			stk.push(pir(nxt, g.v_[nxt].begin()));
			cout << nxt << " ";
      ret.push_back(nxt);
			vis[nxt] = 1;
		}
	}
  return ret;
}



//question 4
Graph4::Graph4(vector<vector<int>> &gr): g4(gr) {}

void Graph4::dfs(int rt, vector<int>& ret, vector<int> &vis){
	ret.push_back(rt);

	for (auto v: g4[rt]){
		if (vis[v] != 1){
			vis[v] = 1;
			dfs(v, ret, vis);
		}
	}
}

vector<int> Graph4::DFS_ALL(){
	vector<int> ret;
	int points = g4.size();
	vector<int> vis(points, 0);

		for (int i = 0; i < points; i++){
		if (vis[i] == 0){
				vis[i] = 1;
				dfs(i, ret, vis);
			}
	}
		return ret;
}

//question 5
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
	// x - 1, y
	// x, y - 1
	// x + 1, y
	// x, y + 1
bool Maze::inrange(int x, int y){
	return !(x < 0 || x > mazeg.size() -1 || y > mazeg.size()-1 || y < 0);
}

void Maze::bfs(int x, int y){
	typedef pair<int, int> pir;
	memset(vis, 0, sizeof(vis));
	queue<pir> que;
	que.push(pir(x, y));
	vis[x][y] = 1;

  while (!que.empty()){
		pir T = que.front(); 
		que.pop();
		for (int i = 0; i < 4; i++){
			int nx = dx[i] + T.first;
			int ny = dy[i] + T.second;
			if (inrange(nx, ny) && mazeg[nx][ny] != 0 && vis[nx][ny] == 0){
				que.push(pir(nx, ny));
				vis[nx][ny] = 1;
			}
		}
	}
}


//question 6: rearrange the vector 
void Sort::partition (vector<int> &input, int index, int low, int high){
  swap(input[index], input[high - 1]);
  int i = low -1;

  for(int j = low; j < high - 1; j++){
    if(input[j] < input[high - 1]){
      i++;
      swap(input[i], input[j]);
    }
  }
  swap(input[i + 1], input[index - 1]);
}