#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;


vector<pair<int, int>> adj[10005];
bool chk[10005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v, e; cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b, cost; cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    chk[1] = 1;
    for(auto nxt : adj[1]) pq.push({nxt.X, nxt.Y});
    int cnt = 0, ans = 0;
    while(cnt < v-1){
        auto cur = pq.top(); pq.pop();
        if(chk[cur.Y]) continue;
        for(auto nxt : adj[cur.Y]){
            if(!chk[nxt.Y]) pq.push({nxt.X, nxt.Y});
        }
        ans += cur.X;
        chk[cur.Y] = 1;
        cnt++;
    }
    cout << ans << '\n';
    return 0;
}