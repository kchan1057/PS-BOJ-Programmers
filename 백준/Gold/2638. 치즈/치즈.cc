#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int board[105][105];
int dist[105][105]; // 치즈가 공기와 접촉한 횟수
bool vis[105][105]; // 외부 공기 탐색을 위한 방문 배열
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

// 보드에 치즈(1)가 남아있는지 확인하는 함수
bool has_cheese() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) return true;
        }
    }
    return false;
}

// 2회 이상 접촉한 치즈를 녹이는 함수
void erase_cheese() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] >= 2) board[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> board[i][j];
    }

    int ans = 0;
    while (has_cheese()) {
        // 매 턴마다 초기화
        memset(dist, 0, sizeof(dist));
        memset(vis, 0, sizeof(vis));
        
        queue<pair<int, int>> Q;
        // 가장자리는 항상 치즈가 없으므로 (0,0)에서 외부 공기 BFS 시작
        Q.push({0, 0});
        vis[0][0] = true;

        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (vis[nx][ny]) continue;

                if (board[nx][ny] == 1) {
                    // 치즈를 만나면 큐에 넣지는 않고, 접촉 횟수만 증가
                    dist[nx][ny]++;
                } else {
                    // 공기(0)를 만나면 방문 표시 후 계속 탐색
                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
        }
        
        erase_cheese();
        ans++;
    }

    cout << ans << '\n';
    return 0;
}