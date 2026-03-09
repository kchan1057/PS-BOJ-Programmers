#include <bits/stdc++.h>
using namespace std;
int dist[100005];
int cnt[100005];
bool chk;
vector<int> ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    if (n == k) {
        cout << 0 << '\n';
        cout << n;
        return 0;
    }
    memset(dist, -1, sizeof(dist));
    queue<int> Q; Q.push(n);
    dist[n] = 0; int mx = 0;
    while(!Q.empty()){
        if(chk) break;
        auto cur = Q.front(); Q.pop();
        for(auto nxt : {cur-1, cur+1, 2*cur}){
            if(nxt < 0 || nxt > 100000 || dist[nxt] != -1) continue;
            if(nxt == k && !chk){
                mx = dist[cur]+1;
                chk = true;
                cnt[nxt] = cur;
                break;
            }
            cnt[nxt] = cur;
            Q.push(nxt);
            dist[nxt] = dist[cur]+1;
        }
    }
    int cur = k;
    while(cur != n){
        ans.push_back(cur);
        cur = cnt[cur];
    }
    ans.push_back(n);
    reverse(ans.begin(), ans.end());
    cout << mx << '\n';
    for(auto cur : ans) cout << cur << " ";
    return 0;
}