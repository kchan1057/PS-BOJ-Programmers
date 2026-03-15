#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int, int>> adj[1005];
bool chk[1005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i <= m; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    int max_ans = 0, min_ans = 0, cnt = 0;
    priority_queue<pair<int, int>> pq_max;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_min;
    
    for(auto nxt : adj[0]){
        pq_max.push({nxt.X, nxt.Y});
        pq_min.push({nxt.X, nxt.Y});
    }
    chk[0] = 1;
    while(cnt < n){
        auto cur = pq_max.top(); pq_max.pop();
        if(chk[cur.Y]) continue;
        chk[cur.Y] = 1; cnt++;
        if(cur.X == 0) max_ans++;
        for(auto nxt : adj[cur.Y]){
            if(!chk[nxt.Y]) pq_max.push({nxt.X, nxt.Y}); 
        }
    }

    memset(chk, 0, sizeof(chk)); cnt = 0;
    chk[0] = 1;
    while(cnt < n){
        auto cur = pq_min.top(); pq_min.pop();
        if(chk[cur.Y]) continue;
        chk[cur.Y] = 1; cnt++;
        if(cur.X == 0) min_ans++;
        for(auto nxt : adj[cur.Y]){
            if(!chk[nxt.Y]) pq_min.push({nxt.X, nxt.Y});
        }
    }

    cout << min_ans*min_ans - max_ans*max_ans << '\n';
    return 0;
}