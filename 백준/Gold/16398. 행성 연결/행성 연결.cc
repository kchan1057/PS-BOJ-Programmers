#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int, int>> adj[1005];
bool chk[1005];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int cost; cin >> cost;
            if(i == j) continue;
            adj[i].push_back({cost, j});
            adj[j].push_back({cost, i});
        }
    }
    chk[1] = 1;
    long long ans = 0;
    int cnt = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    for(auto nxt : adj[1]) pq.push({nxt.X, 1, nxt.Y});
    while(cnt < n-1) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if(chk[b]) continue;
        chk[b] = 1;
        ans += cost;
        cnt++;
        for(auto nxt : adj[b]){
            if(!chk[nxt.Y]) pq.push({nxt.X, b, nxt.Y});
        }
    }
    cout << ans << '\n';
    return 0;
}