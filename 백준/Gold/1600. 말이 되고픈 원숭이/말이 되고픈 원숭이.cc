#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx_h[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy_h[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[202][202];
int dist[202][202][32];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dist, -1, sizeof(dist));
    int c, w, h; cin >> c >> w >> h;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) cin >> board[i][j];
    }
    if(w == 1 && h == 1){
        cout << 0;
        return 0;
    }
    queue<tuple<int, int, int>> Q;
    dist[0][0][0] = 0; Q.push({0, 0, 0});
    while(!Q.empty()){
        int x, y, k;
        tie(x, y, k) = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = dx[dir] + x;
            int ny = dy[dir] + y;
            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(board[nx][ny] == 1 || dist[nx][ny][k] != -1) continue;
            if(nx == h-1 && ny == w-1){
                cout << dist[x][y][k] + 1;
                return 0;
            }
            Q.push({nx, ny, k});
            dist[nx][ny][k] = dist[x][y][k] + 1;
        }
        if(k < c){
            for(int dir = 0; dir < 8; dir++){
                int nx = dx_h[dir] + x;
                int ny = dy_h[dir] + y;
                if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                if(board[nx][ny] == 1 || dist[nx][ny][k+1] != -1) continue;
                if(nx == h-1 && ny == w-1){
                    cout << dist[x][y][k] + 1;
                    return 0;
                }   
                Q.push({nx, ny, k+1});
                dist[nx][ny][k+1] = dist[x][y][k] + 1;
            }
        }
    }
    cout << -1;
    return 0;   
}