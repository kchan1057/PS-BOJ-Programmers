#include <bits/stdc++.h>
using namespace std;

int n, m, result = 0;
int board[9][9], temp[9][9];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

// 바이러스 퍼뜨리기 (BFS)
void spreadVirus() {
    int afterSpread[9][9];
    memcpy(afterSpread, temp, sizeof(temp));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (afterSpread[i][j] == 2) q.push({i, j});

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && afterSpread[nx][ny] == 0) {
                afterSpread[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }

    // 안전 영역 계산
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (afterSpread[i][j] == 0) cnt++;
    
    result = max(result, cnt);
}

// 벽 세우기 (DFS)
void setWall(int count) {
    if (count == 3) {
        spreadVirus();
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0) {
                temp[i][j] = 1; // 벽 세우기
                setWall(count + 1);
                temp[i][j] = 0; // 되돌리기 (백트래킹)
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> board[i][j];

    // 원본 보드를 보존하며 탐색
    memcpy(temp, board, sizeof(board));
    setWall(0);

    cout << result;
    return 0;
}