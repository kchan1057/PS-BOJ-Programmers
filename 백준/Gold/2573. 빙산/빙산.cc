#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m;
int board[303][303];
int vis[303][303];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = 1;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] > 0 && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}
void melt() {
    int temp[303][303] = {0,};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) continue;
            int sea_cnt = 0;
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (board[nx][ny] == 0) sea_cnt++;
            }
            temp[i][j] = max(0, board[i][j] - sea_cnt);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) board[i][j] = temp[i][j];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> board[i][j];
    }
    int year = 0;
    while (true) {
        int chunks = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] > 0 && !vis[i][j]) {
                    chunks++;
                    bfs(i, j);
                }
            }
        }
        if (chunks >= 2) {
            cout << year;
            return 0;
        }
        if (chunks == 0) {
            cout << 0;
            return 0;
        }
        melt(); 
        year++;
    }
}