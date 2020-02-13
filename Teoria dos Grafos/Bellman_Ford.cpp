#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef pair < lli, lli > ii;
typedef vector < ii > vii;

vector < lli > distances;
vector < vii > graph;
lli vertex, edges;

void Bellman_Ford(lli start) {
    distances[start] = 0;
    for(lli i = 0; i < vertex - 1; i++) {
        for(lli j = 1; j <= vertex; ++j) {
            for(auto x: graph[j]) {
                if(distances[j] != INT_MAX and distances[j] + x.second < distances[x.first]) {
                    distances[x.first] = distances[j] + x.second;
                }
            }
        }
    }
}

int main() {
    cin >> vertex >> edges;
    graph.resize(vertex + 1);
    distances.resize(vertex + 1, INT_MAX);
    for(lli i = 0; i < edges; ++i) {
        lli u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back(make_pair(v, c));
        graph[v].push_back(make_pair(u, c));
    }
    Bellman_Ford(1);
    cout << distances[vertex] << endl;
    return 0;
}