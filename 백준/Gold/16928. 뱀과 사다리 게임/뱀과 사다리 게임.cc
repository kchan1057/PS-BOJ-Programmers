#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, m;
int board[102];
int trans[105];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int cnt = 0;
    fill(board, board+102, -1);
    for(int i = 0; i < n+m; i++){
        int a, b; cin >> a >> b;
        trans[a] = b;
    }
    queue<int> Q;
    board[1] = 0;
    if(trans[1] != 0){
        board[trans[1]] = 1;
        Q.push(trans[1]);
    }
    else Q.push(1);
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int nxt : {cur+1, cur+2, cur+3, cur+4, cur+5, cur+6}){
            if(nxt > 100) continue;
            if(trans[nxt] != 0) nxt = trans[nxt];
            if(board[nxt] != - 1) continue;
            if(nxt == 100){
                cout << board[cur]+1;
                return 0;
            }
            board[nxt] = board[cur]+1;
            Q.push(nxt);

        }
    }
    return 0;
}