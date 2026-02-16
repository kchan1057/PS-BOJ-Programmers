#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<int> result;
const int INF = 0x3f3f3f3f;
int score[105];
int board[105][105];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, r; cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) cin >> score[i];
    for(int i = 1; i <= n; i++) fill(board[i], board[i]+1+n, INF);
    for(int i = 0; i < r; i++) {
        int a, b, cost; cin >> a >> b >> cost;
        board[a][b] = cost;
        board[b][a] = cost;
    }
    for(int i = 1; i <= n; i++) board[i][i] = 0;

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) board[i][j] = min(board[i][k] + board[k][j], board[i][j]);
        }
    }

    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 1; j <= n; j++){
            if(board[i][j] <= m) sum += score[j];
        }
        result.push_back(sum);
    }
    cout << *max_element(result.begin(), result.end());
    return 0;
}