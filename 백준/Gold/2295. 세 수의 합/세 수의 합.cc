#include <bits/stdc++.h>
using namespace std;

int s[1005];
int two[1000005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    sort(s, s+n);
    int k = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            two[k] = s[i] + s[j];
            k++;
        }
    }
    sort(two, two+k);

    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(binary_search(two, two+k, s[i]-s[j])){
                cout << s[i];
                return 0;
            }
        }
    }
    return 0;
}