#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
int dig[100005];
vector<int> result;
vector<int> adj[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--) {
        for(int i = 0; i <= n; i++) adj[i].clear();
        result.clear();
        memset(dig, 0, sizeof(dig));
        cin >> n;
        for(int i = 1; i <= n; i++){
            int a; cin >> a;
            adj[i].push_back(a);
            dig[a]++;
        }
        queue<int> Q;
        for(int i = 1; i <= n; i++){
            if(dig[i] == 0) {
                Q.push(i);
                result.push_back(i);
            }
        }
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for(int nxt : adj[cur]){
                dig[nxt]--;
                if(dig[nxt] == 0) {
                    Q.push(nxt);
                    result.push_back(nxt);
                }
            }
        }
        cout << result.size() << '\n';
    }
    return 0;
}