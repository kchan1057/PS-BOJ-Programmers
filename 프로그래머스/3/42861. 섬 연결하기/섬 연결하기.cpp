#include <string>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
vector<pair<int, int>> adj[102];
bool chk[102];
int solution(int n, vector<vector<int>> costs) {
    int ans = 0, cnt = 0;
    int v = n;
    
    for(int i = 0; i < costs.size(); i++){
        adj[costs[i][0]].push_back({costs[i][2], costs[i][1]});
        adj[costs[i][1]].push_back({costs[i][2], costs[i][0]});
    }
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    for(auto nxt : adj[0]) pq.push({nxt.X, 0, nxt.Y});
    chk[0] = 1;
    while(!pq.empty()) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if(chk[b]) continue;
        ans += cost;
        chk[b] = 1;
        cnt++;
        
        for(auto nxt : adj[b]) {
            if(!chk[nxt.Y])
            pq.push({nxt.X, b, nxt.Y});
        }
    }
    return ans;
}