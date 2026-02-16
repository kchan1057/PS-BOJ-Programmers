#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;


vector<pair<int, int>> adj[1005];
int dist[1005];
const int INF = 0x3f3f3f3f;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, cost; cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
    }
    int st, en; cin >> st >> en;
    fill(dist, dist+1+n, INF);
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
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
    cout << dist[en] - dist[st];
    return 0;
}