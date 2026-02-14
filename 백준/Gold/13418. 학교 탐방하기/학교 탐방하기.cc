#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
bool chk1[1005];
bool chk2[1005];
vector<pair<int, int>> adj[1005];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    priority_queue<tuple<int, int, int>> pq_max;
    priority_queue<tuple<int, int,int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq_min;
    int cnt = 0, max_ans = 0, min_ans = 0;
    for(int i = 0; i < m+1; i++){
        int a, b, cost; cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a});
    }
    for(auto nxt : adj[0]){
        pq_max.push({nxt.X, 0, nxt.Y});
        pq_min.push({nxt.X, 0, nxt.Y});
    }
    chk1[0] = 1, chk2[0] = 1;
    int max_total = 0, min_total = 0;
    while(cnt < n){
        int cost1, a1, b1;
        tie(cost1, a1, b1) = pq_max.top(); pq_max.pop();
        if(chk1[b1]) continue;
        chk1[b1] = 1;
        cnt++;
        if(cost1 == 0) {
            max_ans++;
        }
        for(auto nxt : adj[b1]) {
            if(!chk1[nxt.Y]) pq_max.push({nxt.X, b1, nxt.Y});
        }
    }
    cnt = 0;
    while(cnt < n){
        int cost2, a2, b2;
        tie(cost2, a2, b2) = pq_min.top(); pq_min.pop();
        if(chk2[b2]) continue;
        chk2[b2] = 1;
        cnt++;
        if(cost2 == 0) {
            min_ans++;
        }
        for(auto nxt : adj[b2]) {
            if(!chk2[nxt.Y]) pq_min.push({nxt.X, b2, nxt.Y});
        }
    }
    cout << min_ans*min_ans - max_ans*max_ans << '\n';
    return 0;
}