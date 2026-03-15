#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int s[100005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    int st = 0, en = n-1, min = 0x7fffffff;
    int a = s[0], b = s[n-1];
    while(st < en){
        int sum = s[st] + s[en];
        if(abs(sum) < abs(min)){
            min = s[st]+s[en];
            a = s[st], b = s[en];
        }
        if(sum > 0) en--;
        else st++;
    }
    cout << a << " " << b;
    return 0;
}