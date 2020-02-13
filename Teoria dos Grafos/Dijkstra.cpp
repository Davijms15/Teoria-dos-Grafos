#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef pair < lli, lli > ii;
typedef vector < ii > vii;

vector < lli > distances;
vector < vii > graph;
lli vertex, edges;

void Dijkstra(lli start) {
    distances[start] = 0;
    priority_queue < ii, vii, greater<ii> > pq;
    pq.push(make_pair(distances[start], start));
    while(!pq.empty()) {
        ii u = pq.top();
        pq.pop();
        for(auto x: graph[u.second]) {
            if(u.first + x.second < distances[x.first]) {
                distances[x.first] = u.first + x.second;
                pq.push(make_pair(distances[x.first], x.first));
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
    Dijkstra(1);
    cout << distances[vertex] << endl;
    return 0;
}