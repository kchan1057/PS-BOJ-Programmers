#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
const int INF = 0x3f3f3f3f;
long long dist[805];
long long dist1[805];
long long dist2[805];
vector<pair<int, int>> adj[805];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, e; cin >> n >> e;
    if(e == 0) {cout << -1; return 0;}
    fill(dist, dist+805, INF);
    for(int i = 0; i < e; i++) {
        int a, b, cost; cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a});
    }
    int dot1, dot2; cin >> dot1 >> dot2;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, dot1}); dist[dot1] = 0;
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(dist[cur.Y] < cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            if(dist[cur.Y] + nxt.X < dist[nxt.Y]) {
                dist[nxt.Y] = dist[cur.Y] + nxt.X;
                pq.push({dist[nxt.Y], nxt.Y});
            }
        }
    }
    fill(dist1, dist1+805, INF);
    pq.push({0, dot2}); dist1[dot2] = 0;
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(dist1[cur.Y] < cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            if(dist1[cur.Y] + nxt.X < dist1[nxt.Y]) {
                dist1[nxt.Y] = dist1[cur.Y] + nxt.X;
                pq.push({dist1[nxt.Y], nxt.Y});
            }
        }
    }
    fill(dist2, dist2+805, INF);
    pq.push({0, 1}); dist2[1] = 0;
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(dist2[cur.Y] < cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            if(dist2[cur.Y] + nxt.X < dist2[nxt.Y]) {
                dist2[nxt.Y] = dist2[cur.Y] + nxt.X;
                pq.push({dist2[nxt.Y], nxt.Y});
            }
        }
    }
    long long k = min(dist2[dot1]+dist[dot2]+dist1[n], dist2[dot2]+dist1[dot1]+dist[n]);
    if(k >= INF) cout << -1;
    else cout << k;
    return 0;
}