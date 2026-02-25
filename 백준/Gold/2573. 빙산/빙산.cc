#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[303][303];
bool vis[303][303];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> board[i][j];
    }
    int area = 0, cnt = 0;
    queue<pair<int, int>> Q;
    while(1){
        area = 0;
        memset(vis, false, sizeof(vis));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] != 0 && vis[i][j] == 0){
                    Q.push({i, j});
                    vis[i][j] = 1;
                    area++;
                }
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = dx[dir] + cur.X;
                        int ny = dy[dir] + cur.Y;
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if(vis[nx][ny]) continue;
                        if(board[nx][ny] == 0){
                            if(board[cur.X][cur.Y] > 0) board[cur.X][cur.Y]--;
                        }
                        else{
                            Q.push({nx, ny});
                            vis[nx][ny] = 1;
                        }
                    }

                }
            }
        }
        cnt++;
        if(area > 1){
            cout << cnt-1;
            return 0;
        }
        if(area == 0){
            cout << 0;
            return 0;
        }
    }
    return 0;
}