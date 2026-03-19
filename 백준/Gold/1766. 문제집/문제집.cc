#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<int> adj[32005];
int dig[32005];
vector<int> ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        dig[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> Q;
    for(int i = 1; i <= n; i++){
        if(dig[i] == 0) Q.push(i);
    }
    while(!Q.empty()) {
        auto cur = Q.top(); Q.pop();
        ans.push_back(cur);
        for(auto nxt : adj[cur]){
            dig[nxt]--;
            if(dig[nxt] == 0) Q.push(nxt);
        }
    }
    for(auto cur : ans) cout << cur << " ";
    return 0;
}