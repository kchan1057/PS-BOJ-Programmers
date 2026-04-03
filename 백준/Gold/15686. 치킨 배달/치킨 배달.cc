#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, m;
vector<pair<int, int>> home;
vector<pair<int, int>> chk;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            int k; cin >> k;
            if(k == 1) home.push_back({i, j});
            if(k == 2) chk.push_back({i, j});
        }
    }

    int a = home.size(), b = chk.size();
    home.resize(a); chk.resize(b);
    vector<int> temp(b, 0);
    for(int i = b-m; i < b; i++) temp[i] = 1;

    int ans = INT_MAX;
    do{
        int total = 0;
        for(auto h : home){
            int dist = INT_MAX;
            for(int i = 0; i < b; i++){
                if(temp[i] == 1){
                    dist = min(dist, abs(h.X - chk[i].X) + abs(h.Y - chk[i].Y));
                }
            }
            total += dist;
        }
        ans = min(ans, total);
    } while(next_permutation(temp.begin(), temp.end()));

    cout << ans;
    return 0;
}  