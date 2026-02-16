#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int, int>> adj[20005];
int dist[20005];
const int INF = 0x3f3f3f3f;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int v, e, k; cin >> v >> e >> k;
    fill(dist+1, dist+v+1, INF);
    dist[k] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,k});
    for(int i = 0; i < e; i++){
        int a, b, cost; cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
    }

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(dist[cur.Y] < cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            if(dist[cur.Y] + nxt.X < dist[nxt.Y]){
                dist[nxt.Y] = dist[cur.Y] + nxt.X;
                pq.push({dist[nxt.Y], nxt.Y});
            }
        }
    }
    for(int i = 1; i <= v; i++){
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
    return 0;
}