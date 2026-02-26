#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
vector<pair<int, int>> adj[1005];
vector<pair<int, int>> adj_rev[1005];
const int INF = 0x3f3f3f3f;
int dist[1005];
int dist_rev[1005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, x; cin >> n >> m >> x;
    for(int i = 0; i < m; i++){
        int a, b, cost; cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj_rev[b].push_back({cost, a});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist+1005, INF); 
    pq.push({0, x}); dist[x] = 0;
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
    fill(dist_rev, dist_rev + 1005, INF);
    dist_rev[x] = 0; pq.push({0, x});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(dist_rev[cur.Y] < cur.X) continue;
        for(auto nxt : adj_rev[cur.Y]){
            if(dist_rev[cur.Y] + nxt.X < dist_rev[nxt.Y]){
                dist_rev[nxt.Y] = dist_rev[cur.Y] + nxt.X;
                pq.push({dist_rev[nxt.Y], nxt.Y});
            }
        }
    }
    int max = 0;
    for(int i = 1; i <= n; i++){
        if(max < dist[i] + dist_rev[i] && dist[i]+dist_rev[i] < INF) max = dist[i] + dist_rev[i];
    }
    cout << max;
    return 0;   
}