#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#define X first
#define Y second
using namespace std;

vector<pair<int, int>> adj[55];
const int INF = 1e9+10;
int d[55];
int solution(int N, vector<vector<int> > road, int K) {
    fill(d, d+55, INF);
    
    for(int i = 0; i < road.size(); i++){
        adj[road[i][0]].push_back({road[i][2], road[i][1]});
        adj[road[i][1]].push_back({road[i][2], road[i][0]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    d[1] = 0;
    pq.push({d[1], 1});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        
        for(auto nxt : adj[cur.Y]) {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(d[i] <= K) ans++;
    }
    return ans;
}