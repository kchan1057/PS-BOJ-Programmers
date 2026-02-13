#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector<pair<int, int>> adj[100005];
bool chk[100005];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    long long ans = 0;

    for(int i = 0; i < m; i++){
        int a, b, cost; cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a});
    }
    chk[1] = 1;
    int cnt = 0;
    int max = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    for(auto nxt : adj[1]) pq.push({nxt.X, 1, nxt.Y});
    while(cnt < n - 1){
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if(chk[b]) continue;
        chk[b] = 1;
        cnt++;
        if(cost > max) max = cost;
        ans += cost;
        for(auto nxt : adj[b]) pq.push({nxt.X, b, nxt.Y});
    }
    cout << ans-max << '\n';
    return 0;
}