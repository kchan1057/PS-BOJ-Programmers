#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
int dig[100005];
vector<int> result;
bool vis[100005];
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

    while(!Q.empty()){
        int cur = Q.top(); Q.pop();
        if(!vis[cur]) result.push_back(cur);
        vis[cur] = 1;
        for(int nxt : adj[cur]){
            dig[nxt]--;
            if(dig[nxt] == 0){
                Q.push(nxt);
            }
        }
    }
    for(int nxt : result) cout << nxt << " ";
    return 0;   
}