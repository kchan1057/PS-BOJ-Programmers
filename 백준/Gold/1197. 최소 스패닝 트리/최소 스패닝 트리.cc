#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

bool chk[10005];
vector<pair<int, int>> adj[10005];
int v, e; 
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> v >> e;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    for(int i = 0; i < e; i++){
        int a, b, cost; cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a}); // a 정점 c 가격 b 정점
    }
    int cnt = 0;
    chk[1] = 1;
    for(auto nxt : adj[1]) pq.push({nxt.X, 1, nxt.Y});
    long long total_cost = 0;
    while(cnt < v-1){
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if(chk[b]) continue;
        total_cost += cost;
        cnt++;
        chk[b] = 1;
        for(auto nxt : adj[b]) {
            if(!chk[nxt.Y]) pq.push({nxt.X, b, nxt.Y});
        }
    }
    cout << total_cost << '\n';
    return 0;
}