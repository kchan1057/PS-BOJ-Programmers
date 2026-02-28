#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        vector<int> adj[100005] = {};
        int dig[100005] = {};
        vector<int> result = {};
        for(int i = 1; i <= n; i++){
            int k; cin >> k;
            adj[i].push_back(k);
            dig[k]++;
        }
        queue<int> Q;
        for(int i = 1; i <= n; i++){
            if(dig[i] == 0){
                Q.push(i);
                result.push_back(i);
            } 
        }

        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for(int nxt : adj[cur]){
                dig[nxt]--;
                if(dig[nxt] == 0){
                    Q.push(nxt);
                    result.push_back(nxt);
                }
            }
        }
        cout << result.size() << '\n';
    }
    return 0;   
}