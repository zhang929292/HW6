#include <iostream>
#include "src/lib/solution.h"


int main()
{
//question 3 start: DFS graph without direction 
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
    cout<< "Output of question 3: [ ";
	g.DFS(g, rt);
    cout<< "]" << endl;


//question 4 start: DFS graph with direction 
	int points = 7;
    int edges = 8;
	vector<vector<int>> g4;
    g4.resize(points);
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
    cout << "Output of question 4: [ ";
    vector<int> ans = graph4.DFS_ALL();
	for (auto v:ans){
        cout << v << " ";
    }
	cout <<"]"<< endl;

//question 5
    vector<vector<int>> mazeg = {{1, 1, 0, 0, 0}, 
							{1, 0, 1, 1, 1}, 
							{1, 1, 0, 0, 1}, 
							{1, 1, 0, 0, 1}, 
							{1, 1, 1, 1, 1}};

	Maze maze(mazeg);
	int sx, sy, ex, ey;
	sx = 0;
	sy = 0;
    ex = 4;
	ey = 4;
	maze.bfs(sx, sy);
	cout << "Output of question 5: ";
	if (maze.vis[ex][ey] == 1)
		cout << "True" << endl;
	else
		cout << "False" << endl;

//question 6 start:
    Sort sort;
    vector<int> input = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    sort.partition(input, 9, 0, 9);
    cout<<"Output of question 6: [ ";
    for(auto it=input.begin(); it!=input.end(); it++){
        cout<< *it<< " ";
    }cout<<"]"<<endl;


    return EXIT_SUCCESS;
}