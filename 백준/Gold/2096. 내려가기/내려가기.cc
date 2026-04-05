#include<bits/stdc++.h>
using namespace std;
int max_d[2][3];
int min_d[2][3];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;
    max_d[1][1] = min_d[1][1] = a;
    max_d[1][2] = min_d[1][2] = b;
    max_d[1][3] = min_d[1][3] = c;
    for(int i = 2; i <= n; i++){
        cin >> a >> b >> c;
        int cur = i % 2;
        int prev = (i - 1) % 2;
        max_d[cur][1] = max(max_d[prev][1] + a, max_d[prev][2] + a);
        max_d[cur][2] = max({max_d[prev][1] + b, max_d[prev][2] + b, max_d[prev][3] + b});
        max_d[cur][3] = max(max_d[prev][2] + c, max_d[prev][3] + c);
        min_d[cur][1] = min(min_d[prev][1] + a, min_d[prev][2] + a);
        min_d[cur][2] = min({min_d[prev][1] + b, min_d[prev][2] + b, min_d[prev][3] + b});
        min_d[cur][3] = min(min_d[prev][2] + c, min_d[prev][3] + c);
    }
    cout << max({max_d[n%2][1], max_d[n%2][2], max_d[n%2][3]}) << " " << min({min_d[n%2][1], min_d[n%2][2], min_d[n%2][3]});
    return 0;
}