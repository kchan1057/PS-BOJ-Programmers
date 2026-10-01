#include <string>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
bool vis[102];
vector<pair<int, int >> adj[102];
int solution(int n, vector<vector<int>> costs) {
    for(int i = 0; i < costs.size(); i++){
        adj[costs[i][0]].push_back({costs[i][2], costs[i][1]});
        adj[costs[i][1]].push_back({costs[i][2], costs[i][0]});
    }
    int cnt = 0, ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto cur : adj[0]){
        pq.push({cur.X, cur.Y});
    }
    vis[0] = 1;
    while(cnt < n - 1){
        auto cur = pq.top(); pq.pop();
        if(vis[cur.Y]) continue;
        vis[cur.Y] = 1;
        ans += cur.X;
        cnt++;
        for(auto nxt : adj[cur.Y]){
            if(vis[nxt.Y]) continue;
            pq.push({nxt.X, nxt.Y});
        }
    }
    return ans;
}