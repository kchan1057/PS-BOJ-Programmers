#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

string board[1005];
int dist1[1005][1005];
int dist2[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--){
        int w, h; cin >> w >> h;
        queue<pair<int, int>> Q1; // 상근
        queue<pair<int, int>> Q2; // 불
        memset(dist1, -1, sizeof(dist1));
        memset(dist2, -1, sizeof(dist2));
        for(int i = 0; i < h; i++) {
            cin >> board[i];
            for(int j = 0; j < w; j++){
                if(board[i][j] == '@') {
                    Q1.push({i, j});
                    dist1[i][j] = 0;
                }
                if(board[i][j] == '*'){
                    Q2.push({i, j});
                    dist2[i][j] = 0;
                }
            }
        }

        while(!Q2.empty()){
            auto cur = Q2.front(); Q2.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = dx[dir] + cur.X;
                int ny = dy[dir] + cur.Y;
                if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                if(dist2[nx][ny] != -1 || board[nx][ny] == '#') continue;
                dist2[nx][ny] = dist2[cur.X][cur.Y]+1;
                Q2.push({nx, ny});
            }
        }

        int chk = false;
        while(!Q1.empty() && !chk){
            auto cur = Q1.front(); Q1.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = dx[dir] + cur.X;
                int ny = dy[dir] + cur.Y;
                if(nx < 0 || ny < 0 || nx >= h || ny >= w){
                    cout << dist1[cur.X][cur.Y]+1 << '\n';
                    chk = true;
                    break;
                }
                if(board[nx][ny] == '#' || dist1[nx][ny] != -1) continue;
                if(dist2[nx][ny] != -1 && dist2[nx][ny] <= dist1[cur.X][cur.Y]+1) continue;
                Q1.push({nx, ny});
                dist1[nx][ny] = dist1[cur.X][cur.Y]+1;
            }
        }
        if(!chk) cout << "IMPOSSIBLE\n";
    }
    return 0;
}