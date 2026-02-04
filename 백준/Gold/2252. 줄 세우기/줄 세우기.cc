#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[100005];
int dig[100005];
bool vis[100005];
vector<int> result;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while(m--){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        dig[b]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(dig[i] == 0){
            q.push(i);
            result.push_back(i);
        }
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){
            dig[nxt]--;
            if(dig[nxt] == 0){
                q.push(nxt);
                result.push_back(nxt);
            }
        }
    }
    for(int cur : result) cout << cur << " ";
    return 0;
}