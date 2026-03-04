#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vc;
int d[102][100002];
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n, k; cin >> n >> k;
    vc.push_back({0, 0});
    for(int i = 0; i < n; i++){
        int w, v; cin >> w >> v;
        vc.push_back({w, v});
    }
    for(int i = 1; i <= n; i++){
        int weight = vc[i].first;
        int value = vc[i].second;
        for(int j = 1; j <= k; j++){
            if(j < weight) d[i][j] = d[i-1][j];
            else d[i][j] = max(d[i-1][j], d[i-1][j-weight]+value);
        }
    }
    cout << d[n][k];
    return 0;
}  