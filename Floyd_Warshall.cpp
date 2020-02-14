#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector < vector < lli > > graph;
lli N, M;

void Floyd_Warshall() {
    for(lli k = 1; k <= N; ++k) {
        for(lli i = 1; i <= N; ++i) {
            for(lli j = 1; j <= N; ++j) {
                if(graph[i][k] + graph[k][j] < graph[i][j]) graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

int main() {
    cin >> N >> M;
    graph.resize(N + 1);
    for(lli i = 0; i < M; ++i) {
        lli u, v, c;
        cin >> u >> v >> c;
        if(graph[u].size() == 0) {
            graph[u].resize(N + 1, INT_MAX);
            graph[u][u] = 0;
        }
        if(graph[v].size() == 0) {
            graph[v].resize(N + 1, INT_MAX);
            graph[v][v] = 0;
        }
        graph[u][v] = graph[v][u] = c;
    }
    Floyd_Warshall();
    for(lli i = 1; i <= N; ++i) {
        for(lli j = 1; j <= N; ++j) {
            cout << "Distance from " << i << " to " << j << " = " << graph[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}