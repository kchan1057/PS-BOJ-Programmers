#include <bits/stdc++.h>
using namespace std;
int dist[100005];
int cnt[100005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    if (n == k) {
        cout << 0 << '\n' << 1 << '\n';
        return 0;
    }
    memset(dist, -1, sizeof(dist));
    dist[n] = 0; cnt[n] = 1;
    queue<int> Q; Q.push(n);
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (int nxt : {cur - 1, cur + 1, 2 * cur}) {
            if (nxt < 0 || nxt > 100000) continue;
            if (dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                cnt[nxt] = cnt[cur];
                Q.push(nxt);
            }
            else if (dist[nxt] == dist[cur] + 1) cnt[nxt] += cnt[cur];  
        }
    }
    cout << dist[k] << '\n' << cnt[k];
    return 0;
}