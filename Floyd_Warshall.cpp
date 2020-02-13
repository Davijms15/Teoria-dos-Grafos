#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector < vector < lli > > distances, edges;
lli N, M;

void Floyd_Warshall() {
    for(lli i = 1; i <= N; ++i) {
        distances[i].resize(N + 1);
        for(lli j = 1; j <= N; ++j) {
            if(i == j) distances[i][j] = 0;
            else if(edges[i][j] != -1) distances[i][j] = edges[i][j];
            else distances[i][j] = INT_MAX;
        }
    }

    for(lli k = 1; k <= N; ++k) {
        for(lli i = 1; i <= N; ++i) {
            for(lli j = 1; j <= N; ++j) {
                if(distances[i][k] + distances[k][j] < distances[i][j]) distances[i][j] = distances[i][k] + distances[k][j];
            }
        }
    }
}

int main() {
    cin >> N >> M;
    distances.resize(N + 1);
    edges.resize(N + 1);
    for(lli i = 0; i < M; ++i) {
        lli u, v, c;
        cin >> u >> v >> c;
        if(edges[u].size() == 0) edges[u].resize(N + 1, -1);
        if(edges[v].size() == 0) edges[v].resize(N + 1, -1);
        edges[u][v] = edges[v][u] = c;
    }
    Floyd_Warshall();
    cout << distances[1][N] << endl;
    return 0;
}