#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int, int>> adj[1005];
int dist1[10005], dist2[10005];
vector<int> result;
const int INF = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x; cin >> n >> m >> x;
    vector<int> result;
    for(int i = 0; i < m; i++){
        int a, b, cost; cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist1, dist1+10005, INF);
    pq.push({0, x}); dist1[x] = 0;
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(dist1[cur.Y] < cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            if(dist1[cur.Y] + nxt.X < dist1[nxt.Y]){
                dist1[nxt.Y] = dist1[cur.Y] + nxt.X;
                pq.push({dist1[nxt.Y], nxt.Y});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        fill(dist2, dist2+10005, INF);
        dist2[i] = 0; pq.push({0, i});
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            if(dist2[cur.Y] < cur.X) continue;
            for(auto nxt : adj[cur.Y]){
                if(dist2[cur.Y] + nxt.X < dist2[nxt.Y]){
                    dist2[nxt.Y] = dist2[cur.Y] + nxt.X;
                    pq.push({dist2[nxt.Y], nxt.Y});
                }
            }
        }
        result.push_back(dist2[x] + dist1[i]);
    }
    cout << *max_element(result.begin(), result.end());
    return 0;
}