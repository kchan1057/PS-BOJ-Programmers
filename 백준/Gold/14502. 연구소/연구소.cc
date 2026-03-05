#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[9][9];
int cpyBoard[9][9];
vector<int> ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    queue<pair<int, int>> Q;
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < m; j++) cin >> board[i][j];
    }
    for(int i = 0; i < n*m; i++){
        for(int j = i+1; j < n*m; j++){
            for(int k = j+1; k < n*m; k++){
                for(int t = 0; t < n; t++){
                    for(int s = 0; s < m; s++) {
                        cpyBoard[t][s] = board[t][s];
                        if(board[t][s] == 2) Q.push({t, s});
                    }
                }
                if(cpyBoard[i/m][i%m] == 0 && cpyBoard[j/m][j%m] == 0 && cpyBoard[k/m][k%m] == 0) cpyBoard[i/m][i%m] = 1, cpyBoard[j/m][j%m] = 1, cpyBoard[k/m][k%m] = 1;
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = dx[dir] + cur.X;
                        int ny = dy[dir] + cur.Y;
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if(cpyBoard[nx][ny] == 1 || cpyBoard[nx][ny] == 2) continue;
                        Q.push({nx, ny});
                        cpyBoard[nx][ny] = 2;
                    }
                }
                int maxArea = 0;
                for(int t = 0; t < n; t++){
                    for(int s = 0; s < m; s++){
                        if(cpyBoard[t][s] == 0) maxArea++;
                    }
                }
                ans.push_back(maxArea);
            }
        }
    }
    cout << *max_element(ans.begin(), ans.end());
    return 0;
}  