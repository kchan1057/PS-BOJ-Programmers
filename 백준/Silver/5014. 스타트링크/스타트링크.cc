#include <bits/stdc++.h>
using namespace std;
int dist[2000005];
int vis[2000005];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int f, s, g, u, d; cin >> f >> s >> g >> u >> d;
    fill(dist, dist+2000005, -1);
    queue<int> q; q.push(s);
    dist[s] = 0, vis[s] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : {cur+u, cur-d}){
            if(nxt > f || nxt < 1) continue;
            if(vis[nxt]) continue;
            dist[nxt] = dist[cur] + 1;
            vis[nxt] = 1;
            q.push(nxt);
        }
    }
    if(dist[g] != -1) cout << dist[g];
    else cout << "use the stairs";
    return 0;
}