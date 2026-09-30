#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
const int INF = 1e9+10;
vector<pair<int, int>> adj[52];
int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    int dist[52]; fill(dist, dist + 52, INF);
    
    for(int i = 0; i < road.size(); i++){
        adj[road[i][0]].push_back({road[i][2], road[i][1]});
        adj[road[i][1]].push_back({road[i][2], road[i][0]});
    }
    
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[1], 1});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(dist[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]) {
            if(dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;
            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            pq.push({dist[nxt.Y], nxt.Y});
        }
    }
    for(int i = 1; i <= N; i++){
        if(dist[i] > K) continue;
        answer++;
    }
    return answer;
}