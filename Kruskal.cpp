#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector < lli > vi;
typedef tuple < lli, lli, lli > iii;
typedef vector < iii > viii;

vi dads, ranks;
viii edges;

lli Find(lli x) {
    if(x == dads[x]) {
        return x;
    }
    return dads[x] = Find(dads[x]);
}

void Union(lli x, lli y) {
    if(ranks[x] >= ranks[y]) {
        dads[y] = x;
        if(ranks[x] == ranks[y]) {
            ranks[x]++;
        }
    } else {
        dads[x] = y;
    }
}

void Kruskal() {
    lli cost = 0;
    for(auto i: edges) {
        lli x = Find(get<1>(i));
        lli y = Find(get<2>(i));
        if(x != y) {
            Union(x, y);
            cost += get<0>(i);
        }
    }
    cout << cost << endl;
}

int main () {
    lli N, M;
    cin >> N >> M;
    dads.resize(N + 1);
    ranks.resize(N + 1);
    edges.resize(N + 1);
    for(lli i = 0; i <= N; ++i) {
        dads[i] = i;
    }
    for(lli i = 0; i < M; ++i) {
        lli u, v, c;
        cin >> u >> v >> c;
        edges.push_back(make_tuple(c, u, v));
        edges.push_back(make_tuple(c, v, u));
    }
    sort(edges.begin(), edges.end());
    Kruskal();
    return 0;
}