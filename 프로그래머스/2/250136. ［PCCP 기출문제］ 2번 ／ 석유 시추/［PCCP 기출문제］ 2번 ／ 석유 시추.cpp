#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#define X first
#define Y second
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[505][505];
bool vis[505][505];

int solution(vector<vector<int>> land) {
    int n = land.size(), m = land[0].size();
    queue<pair<int, int>> Q;
    vector<int> vc(250000);
    int area = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(land[i][j] == 0 || vis[i][j]) continue;
            area++;
            board[i][j] = area;
            Q.push({i, j});
            vis[i][j] = 1;
            int cnt = 0;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                cnt++;
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if(land[nx][ny] == 0 || vis[nx][ny]) continue;
                    board[nx][ny] = area;
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                } 
            }
            vc[area] = cnt;
        }
    }
    vector<int> result(505);
    
    for(int i = 0; i < m; i++){
        set<int> st; bool chk[250000] = {};
        for(int j = 0; j < n; j++){
            if(board[j][i] != 0 && !chk[board[j][i]]) {
                st.insert(board[j][i]);
                chk[board[j][i]] = 1;
            }
        }
        for(int cur : st){
            result[i] += vc[cur];
        }
    }
    return *max_element(result.begin(), result.end());
}