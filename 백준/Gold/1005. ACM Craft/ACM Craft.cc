#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int s[1002];
int dig[1002];
bool vis[1002];
int dp[1002];
vector<int> adj[1002];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--){
        memset(s, 0, sizeof(s));
        memset(dp, 0, sizeof(s));
        memset(dig, 0, sizeof(dig));
        memset(vis, 0, sizeof(vis));
        memset(adj, 0, sizeof(adj));

        int n, k; cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> s[i];
        for(int i = 0; i < k; i++){
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            dig[b]++;
        }
        int aim; cin >> aim;

        priority_queue<int> Q;
        for(int i = 1; i <= n; i++){
            if(dig[i] == 0) {
                Q.push(i);
                vis[i] = 1;
                dp[i] = s[i];
            }
        }
        while(!Q.empty()){
            auto cur = Q.top(); Q.pop();
            for(auto nxt : adj[cur]) {
                if(vis[nxt]) continue;
                dig[nxt]--;
                if(dig[nxt] == 0) {
                    vis[nxt] = 1;
                    Q.push(nxt);
                }
                dp[nxt] = max(dp[nxt], dp[cur] + s[nxt]);
            }
        }
        cout << dp[aim] << '\n';
    }
    return 0;
}  