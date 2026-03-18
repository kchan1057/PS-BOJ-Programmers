#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[1005][1005];
int dist[1005][1005][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        string a; cin >> a;
        for(int j = 0; j < m; j++) board[i+1][j+1] = a[j] -'0';
    }
    if(n == 1 && m == 1){
        cout << 1;
        return 0;
    }
    memset(dist, -1, sizeof(dist));
    queue<tuple<int, int, int>> Q;
    Q.push({1, 1, 0}); dist[1][1][0] = 1;
    while(!Q.empty()) {
        int a, b, state;
        tie(a, b, state) = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = dx[dir] + a;
            int ny = dy[dir] + b;
            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if(dist[nx][ny][state] != -1) continue;
            if(nx == n && ny == m){
                cout << dist[a][b][state] + 1;
                return 0;
            }
            if(board[nx][ny] == 1) {
                if(state == 0){
                    dist[nx][ny][1] = dist[a][b][0] + 1;
                    Q.push({nx, ny, 1});
                }
                else continue;
            }
            else{
                dist[nx][ny][state] = dist[a][b][state] + 1;
                Q.push({nx, ny, state});
            }
        }
    }
    cout << -1;
    return 0;
}