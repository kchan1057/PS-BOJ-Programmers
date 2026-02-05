#include <bits/stdc++.h>
using namespace std;
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, -0, 1, -1};
char board[33][33][33];
int dist[33][33][33];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int l, r, c;
    fill(&dist[0][0][0], &dist[0][0][0] + (33*33*33), -1);
    queue<tuple<int, int, int>> Q;
    while(cin >> l >> r >> c){
        while(!Q.empty()) Q.pop();
        memset(dist, -1, sizeof(dist));
        int ex, ey, ez;
        if(l == 0 && r == 0 && c == 0) break;
        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                string s; cin >> s;
                for(int k = 0; k < c; k++){
                    board[i][j][k] = s[k];
                    if(board[i][j][k] == 'S'){
                        Q.push({i, j, k});
                        dist[i][j][k] = 0;
                    }
                    if(board[i][j][k] == 'E') ex = i, ey = j, ez = k;
                }
            }
        }
        while(!Q.empty()){
            int a, b, t;
            tie(a, b, t) = Q.front(); Q.pop();
            for(int dir = 0; dir < 6; dir++){
                int nx = dx[dir] + a;
                int ny = dy[dir] + b;
                int nz = dz[dir] + t;
                if(nx < 0 || ny < 0 || nz < 0 || nx >= l || ny >= r || nz >= c) continue;
                if(board[nx][ny][nz] == '#' || dist[nx][ny][nz] != -1 ) continue;
                Q.push({nx, ny, nz});
                dist[nx][ny][nz] = dist[a][b][t]+1;
            }
        }
        if(dist[ex][ey][ez] == -1) cout << "Trapped!\n";
        else cout << "Escaped in " << dist[ex][ey][ez] << " minute(s).\n";
    }
    return 0;
}