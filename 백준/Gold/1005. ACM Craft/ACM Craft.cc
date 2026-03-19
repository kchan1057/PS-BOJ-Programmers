#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int buildTime[1005];
int dp[1005];
vector<int> adj[1005];
int dig[1005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) {
        int n, k; cin >> n >> k;
        for(int i = 1; i <= n; i++) adj[i].clear();
        memset(buildTime, 0, sizeof(buildTime));
        memset(dig, 0, sizeof(dig));
        for(int i = 1; i <= n; i++) cin >> buildTime[i];
        for(int i = 0; i < k; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            dig[y]++;
        }
        int w; cin >> w;    
        queue<int> Q;
        for(int i = 1; i <= n; i++){
            if(dig[i] == 0) Q.push(i);
            dp[i] = buildTime[i];
        }
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(auto nxt : adj[cur]){
                dig[nxt]--;
                if(dig[nxt] == 0) Q.push(nxt);
                dp[nxt] = max(dp[nxt], dp[cur]+buildTime[nxt]);
        
            }
        }
        cout << dp[w] << '\n';
    }
    return 0;
}