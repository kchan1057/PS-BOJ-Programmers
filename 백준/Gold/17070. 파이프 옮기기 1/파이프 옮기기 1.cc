#include <iostream>
#include <vector>

using namespace std;

int N;
int board[17][17];
long long dp[17][17][3]; // 0: 가로, 1: 세로, 2: 대각선

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // 1. 초기값 설정: (0, 1) 위치에 가로 방향(0)으로 파이프 끝이 놓임
    dp[0][1][0] = 1;

    // 2. DP 진행 (이중 for문)
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            // 현재 칸이 벽이면 어떤 파이프도 끝점이 될 수 없음
            if (board[i][j] == 1) continue;

            // --- 가로 방향으로 만들기 ---
            // 왼쪽 칸에서 가로(0)였거나 대각선(2)이었을 때 가능
            if (j + 1 < N && board[i][j + 1] == 0) {
                dp[i][j + 1][0] += dp[i][j][0] + dp[i][j][2];
            }

            // --- 세로 방향으로 만들기 ---
            // 위쪽 칸에서 세로(1)였거나 대각선(2)이었을 때 가능
            if (i + 1 < N && board[i + 1][j] == 0) {
                dp[i + 1][j][1] += dp[i][j][1] + dp[i][j][2];
            }

            // --- 대각선 방향으로 만들기 ---
            // 우측 하단 세 칸(오른쪽, 아래, 대각선)이 모두 비어 있어야 함
            if (i + 1 < N && j + 1 < N) {
                if (board[i + 1][j] == 0 && board[i][j + 1] == 0 && board[i + 1][j + 1] == 0) {
                    dp[i + 1][j + 1][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
                }
            }
        }
    }

    // 3. 결과 출력: 목적지 (N-1, N-1)의 모든 상태 합
    long long answer = dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
    cout << answer << endl;

    return 0;
}