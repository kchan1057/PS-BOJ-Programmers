#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
bool truth[51];
bool party[51];
vector<int> adj[51];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;    
    int k; cin >> k;
    for(int i = 0; i < k; i++){
        int a; cin >> a;
        truth[a] = 1;
    }

    for(int i = 1; i <= m; i++){
        int s; cin >> s;
        for(int j = 0; j < s; j++){
            int a; cin >> a;
            adj[i].push_back(a);
        }
    }

    for(int j = 0; j < m; j++){
        for(int i = 1; i <= m; i++){
            if(party[i] == 1) continue;
            for(int nxt : adj[i]){
                if(truth[nxt] == 1) party[i] = 1;
            }
            if(party[i] == 1){
                for(int nxt : adj[i]) truth[nxt] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= m; i++){
        if(party[i] == 0) cnt++;
    }
    cout << cnt;
    return 0;
}  