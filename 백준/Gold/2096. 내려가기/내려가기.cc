#include <bits/stdc++.h>
using namespace std;
int d[2][4];
int s[100005][4];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 3; j++) cin >> s[i][j];
    }
    d[1][1] = s[1][1]; d[1][2] = s[1][2]; d[1][3] = s[1][3];
    for(int i = 2; i <= n; i++){
        d[i%2][1] = max(d[(i-1)%2][1] + s[i][1], d[(i-1)%2][2] + s[i][1]);
        d[i%2][2] = max({d[(i-1)%2][1] + s[i][2], d[(i-1)%2][2] + s[i][2], d[(i-1)%2][3] + s[i][2]});
        d[i%2][3] = max(d[(i-1)%2][2] + s[i][3], d[(i-1)%2][3] + s[i][3]);
    }
    int ansMax = max({d[n%2][1], d[n%2][2], d[n%2][3]});
    memset(d, 0, sizeof(d));
    d[1][1] = s[1][1]; d[1][2] = s[1][2]; d[1][3] = s[1][3];
    for(int i = 2; i <= n; i++){
        d[i%2][1] = min(d[(i-1)%2][1] + s[i][1], d[(i-1)%2][2] + s[i][1]);
        d[i%2][2] = min({d[(i-1)%2][1] + s[i][2], d[(i-1)%2][2] + s[i][2], d[(i-1)%2][3] + s[i][2]});
        d[i%2][3] = min(d[(i-1)%2][2] + s[i][3], d[(i-1)%2][3] + s[i][3]);
    }
    int ansMin = min({d[n%2][1], d[n%2][2], d[n%2][3]});
    cout << ansMax << " " << ansMin;
    return 0;
}