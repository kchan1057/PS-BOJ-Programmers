#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> s(n+1);
    vector<int> dp_down(n+1, 1);
    for(int i = 1; i <= n; i++) cin >> s[i];
    
    for(int i = n; i > 0; i--){
        for(int j = n; j > i; j--){
            if(s[i] > s[j]) dp_down[i] = max(dp_down[i], dp_down[j]+1);
        }
    }
    cout << *max_element(dp_down.begin(), dp_down.end());
    return 0;   
}