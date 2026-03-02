#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> s(n+1);
    vector<int> dp(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        dp[i] = s[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(s[i] > s[j]) dp[i] = max(dp[i], dp[j]+s[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;   
}