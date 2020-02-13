#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef pair < lli, lli > ii;
typedef vector < ii > vii;

vector < bool > visited;
vector < vii > graph;
lli vertex, edges;

void Prim(lli start) {
    lli cost = 0;
    visited[start] = true;
    priority_queue < ii, vii, greater<ii> > pq;
    pq.push(make_pair(visited[start], start));
    while(!pq.empty()) {
        ii u = pq.top();
        pq.pop();
        if(!visited[u.second]) {
            cost += u.first;
            visited[u.second] = true;
        }
        for(auto x: graph[u.second]) {
            if(!visited[x.first]) {
                pq.push(make_pair(x.second, x.first));
            }
        }
    }
    cout << cost << endl;
}

int main() {
    cin >> vertex >> edges;
    graph.resize(vertex + 1);
    visited.resize(vertex + 1, false);
    for(lli i = 0; i < edges; ++i) {
        lli u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back(make_pair(v, c));
        graph[v].push_back(make_pair(u, c));
    }
    Prim(1);
    return 0;
}