#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector<pair<int, int>> adj[305];
bool chk[305];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int v1; cin >> v1; 
    int v2 = v1+1;
    for(int i = 1; i <= v1; i++){
        int k; cin >> k;
        adj[v2].push_back({k, i});
        adj[i].push_back({k, v2});
    }

    for(int i = 1; i <= v1; i++){
        for(int j = 1; j <= v1; j++){
            int k; cin >> k;
            if(i == j) continue;
            adj[i].push_back({k, j});
            adj[j].push_back({k, i});
        }
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    chk[1] = 1;
    int cnt = 0, total_cost = 0;
    for(auto nxt : adj[1]) pq.push({nxt.X, 1, nxt.Y});
    while(cnt < v2 - 1){
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if(chk[b]) continue;
        cnt++;
        chk[b] = 1;
        total_cost += cost;
        for(auto nxt : adj[b]){
            if(!chk[nxt.Y]) pq.push({nxt.X, b, nxt.Y});
        }
    }
    cout << total_cost << '\n';
    return 0;
}