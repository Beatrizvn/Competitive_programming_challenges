/*
Cat Snuke and a Voyage

pdf: https://vjudge.net/contest/578663/problemPrint/B

Input
3 2
1 2
2 3
Output
POSSIBLE

Input
4 3
1 2
2 3
3 4
Output
IMPOSSIBLE

Input
100000 1
1 99999
Output
IMPOSSIBLE

Input
5 5
1 3
4 5
2 3
2 4
1 4
Output
POSSIBLE
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX { 200000 };

int bfs(const vector<vector<int>>& graph, int island1, int vertices) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    
    queue<int> queue;
    queue.push(island1);
    visited[island1] = true;
    
    int numOfNeighbors1 = 0; //to check the number of neighbors to island 1

    while (!queue.empty()) {
        
        int u = queue.front();
        queue.pop();

        if (u != 1) numOfNeighbors1 --;

        for (int v : graph[u]) {
            //cout << "Visitando vértice " << u << " olhando: " << v << endl;

            if(u == 1) numOfNeighbors1 ++;
            
            if(numOfNeighbors1 >= 0 && u != 1 && v == vertices) return 1;

            if (!visited[v]) {
                queue.push(v);
                visited[v] = true;
            }
        }

        //cout << numOfNeighbors1 << endl;
    }

    return 0;
}


int main(){

    int vertices,edge,a,b;
    cin >> vertices >> edge;
    vector<vector<int>> islands(vertices+1);

    for (int i = 0; i < edge; ++i) {
        cin >> a >> b;
        islands[a].push_back(b);
        islands[b].push_back(a);
    }

    //Breadth-first search
    int answer = bfs(islands, 1,vertices);

    if(answer == 1) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}
