#include <bits/stdc++.h>
using namespace std;
int d[105][105];
int nxt[105][105];
const int INF = 0x3f3f3f3f;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        fill(d[i], d[i]+n+1, INF);
        d[i][i] = 0;
    }
    for(int i = 1; i <= m; i++){
        int a, b, cost; cin >> a >> b >> cost;
        d[a][b] = min(d[a][b], cost);
        nxt[a][b] = b;
    } 
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(d[i][k] + d[k][j] < d[i][j]) {
                    nxt[i][j] = nxt[i][k];
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) nxt[i][i] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            if(d[i][j] == INF) cout << "0 ";
            else cout << d[i][j] << " ";
        }
        cout << '\n';
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(d[i][j] == 0 || d[i][j] == INF){
                cout << "0\n";
                continue;
            }
            vector<int> path;
            int st = i;
            while(st != j){
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);
            cout << path.size() << ' ';
            for(auto x : path) cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}