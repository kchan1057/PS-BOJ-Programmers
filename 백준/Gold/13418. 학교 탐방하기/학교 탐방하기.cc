#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int, int>> adj[1005]; // 범위를 1005 정도로 넉넉히
bool chk[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    
    // 입력을 m+1번 받음 (문제 조건에 따라)
    for(int i = 0; i < m + 1; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    int max_ans = 0, min_ans = 0, cnt = 0;
    
    // 1. 오르막길(0)을 최대한 많이 선택하는 경우 (pq_min 사용)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_min;
    
    chk[0] = 1; // 시작점 방문 처리
    for(auto nxt : adj[0]) pq_min.push({nxt.X, nxt.Y});

    while(!pq_min.empty()){
        auto cur = pq_min.top(); pq_min.pop();
        if(chk[cur.Y]) continue; // ★ 필수: 이미 방문했다면 건너뛰기
        
        chk[cur.Y] = 1;
        cnt++;
        if(cur.X == 0) max_ans++; // 오르막길 개수 카운트
        
        for(auto nxt : adj[cur.Y]){
            if(!chk[nxt.Y]) pq_min.push({nxt.X, nxt.Y});
        }
        if(cnt == n) break;
    }

    // 2. 오르막길(0)을 최소한으로 선택하는 경우 (pq_max 사용)
    memset(chk, 0, sizeof(chk)); 
    cnt = 0;
    priority_queue<pair<int, int>> pq_max;
    
    chk[0] = 1; // 시작점 재설정
    for(auto nxt : adj[0]) pq_max.push({nxt.X, nxt.Y});

    while(!pq_max.empty()){
        auto cur = pq_max.top(); pq_max.pop();
        if(chk[cur.Y]) continue; // ★ 필수: 이미 방문했다면 건너뛰기
        
        chk[cur.Y] = 1;
        cnt++;
        if(cur.X == 0) min_ans++; // 오르막길 개수 카운트
        
        for(auto nxt : adj[cur.Y]){
            if(!chk[nxt.Y]) pq_max.push({nxt.X, nxt.Y});
        }
        if(cnt == n) break;
    }

    cout << (long long)max_ans*max_ans - (long long)min_ans*min_ans << '\n';
    return 0;
}