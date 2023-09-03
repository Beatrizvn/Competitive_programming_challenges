/*
Time limit 2000 ms
Mem limit 1048576 kB

link pdf: https://vjudge.net/contest/578663/problemPrint/A

example 1
input
4 3
1 2 3 4
1 3
2 3
2 4
output
2

example 2 
input
6 5
8 6 9 1 2 1
1 3
4 2
4 3
4 6
4 6
output
3

*/

#include <bits/stdc++.h>
using namespace std;

const int MAX { 100000 };
bitset<MAX> visited;
bitset<MAX> good;
using ii = pair<int,int>;

void dfs(vector<vector<ii>>& adj, int u, const vector<int>& elevation) {

    visited[u] = true; // Marca o vértice como visitado

    for (const auto& [v, w] : adj[u]) {

        if((elevation[v-1] < w && good[u]==0))
            good[u] = false;
        else if(elevation[v-1] == w ){
            good[u] = true;
            good[v] = true;
        }
        else
            good[u] = true;

        if (!visited[v]) {
            dfs(adj, v, elevation);
        }
    }
}
    

int main(){
    int n,m,a,b,s,count;
    cin >> n >> m;

    vector<vector<ii>> adj(n+1);
    vector<int> elevation;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        elevation.push_back(a);
    }

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back({b,elevation[a-1]});
        adj[b].push_back({a,elevation[b-1]});
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(adj, i, elevation);
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if(good[i]==0) count++;
    }
    cout << count << endl;

    return 0;
}
