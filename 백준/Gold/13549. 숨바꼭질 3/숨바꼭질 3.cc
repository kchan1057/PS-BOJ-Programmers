#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, k;
int dist[100005];
const int INF = 0x3f3f3f3f;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist+100005, INF);
    pq.push({0, n}); dist[n] = 0;
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(dist[cur.Y] < cur.X) continue;
        for(auto nxt : {cur.Y+1, cur.Y-1, 2*cur.Y}){
            int weight = 0;
            if(nxt < 0 || nxt > 100000) continue;
            if(nxt == 2*cur.Y) weight = 0;
            else weight = 1;
            if(dist[cur.Y] + weight < dist[nxt]){
                dist[nxt] = dist[cur.Y] + weight;
                pq.push({dist[nxt], nxt});
            }
            if(nxt == k){
                cout << dist[k];
                return 0;
            }
        }

    }
    return 0;
}