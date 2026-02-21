#include <bits/stdc++.h>
using namespace std;
int board[1005][1005];
int dist[1005][1005][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string st; cin >> st;
        for(int j = 1; j <= m; j++) board[i][j] = (st[j-1] - '0');
    }
    memset(dist, -1, sizeof(dist));
    if(n == 1 && m == 1) {
        cout << 1;
        return 0;
    }
    queue<tuple<int, int, int>> Q;
    Q.push({1, 1, 0});
    dist[1][1][0] = 1;
    while(!Q.empty()){
        int x, y, broken;
        tie(x, y, broken) = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if(board[nx][ny] == 1 && broken == 0) {
                if(dist[nx][ny][1] == -1) {
                    dist[nx][ny][1] = dist[x][y][0] + 1;
                    Q.push({nx, ny, 1});
                }
            }
            else if(board[nx][ny] == 0) {
                if(dist[nx][ny][broken] == -1) {
                    dist[nx][ny][broken] = dist[x][y][broken] + 1;
                    Q.push({nx, ny, broken});
                }
            }
            if(nx == n && ny == m) {
                cout << dist[nx][ny][broken];
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}