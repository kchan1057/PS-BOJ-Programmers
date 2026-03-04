#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t,n,m; cin >> t;
    int coin[21];
    long long dp[10001] = {0,};
    while(t--){
        cin >> n;
        for(int i = 1 ; i < n+1; i++) cin >> coin[i];
        cin >> m; dp[0] = 1;
        for(int i = 1; i < n+1; i++){
            for(int j = coin[i]; j < m+1; j++) dp[j] += dp[j-coin[i]];
        }
        cout << dp[m] << '\n';
        memset(dp, 0 ,sizeof(dp));
    }
    return 0;
}