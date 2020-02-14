#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector < lli > vi;
typedef vector < vi > vvi;
typedef pair < lli, lli > ii;
typedef vector < ii > vii;

lli vertex, edges;
vvi graph;
vi parent, visited;

bool Bfs() {
    parent.resize(vertex + 1, -1);
    visited.resize(vertex + 1);
    queue <ii> q;
    q.push(make_pair(1, 1));
    while(!q.empty()) {
        ii u = q.front();
        q.pop();
        if(visited[u.first]) continue;
        parent[u.first] = u.second;
        visited[u.first] = 1;
        for(lli i = 1; i <= vertex; ++i) {
            if(graph[u.first][i] > 0 and !visited[i]) {
                q.push(make_pair(i, u.first));
            } 
        }
    }
    if(parent[vertex] != -1) return true;
    return false;
}   

lli Get_Neck_And_Update_Graph() {
    lli smaller = INT_MAX, i = vertex;
    while(i != 1) {
        if(graph[parent[i]][i] < smaller) smaller = graph[parent[i]][i];
        i = parent[i];
    }
    i = vertex;
    while(i != 1) {
        graph[parent[i]][i] -= smaller;
        graph[i][parent[i]] += smaller;
        i = parent[i];
    }
    return smaller;
}

void Ford_Fulkerson() {
    lli max_flow = 0, Neck;
    while(Bfs()) {
        max_flow += Get_Neck_And_Update_Graph();
        parent.clear();
        visited.clear();
    }
    cout << "Max Flow = " << max_flow << endl;
}

int main() {
    cin >> vertex >> edges;
    graph.resize(vertex + 1);
    for(lli i = 0; i < edges; ++i) {
        lli u, v, c;
        cin >> u >> v >> c;
        if(!graph[u].size()) graph[u].resize(vertex + 1);
        if(!graph[v].size()) graph[v].resize(vertex + 1);
        graph[u][u] = graph[v][v] = 0;
        graph[u][v] = c;
        graph[v][u] = 0;
    }
    Ford_Fulkerson();
    return 0;
}