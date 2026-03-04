#include <bits/stdc++.h>
using namespace std;

int max_d[2][4], min_d[2][4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    
    // 첫 번째 줄 입력 처리
    int a, b, c;
    cin >> a >> b >> c;
    max_d[1][1] = min_d[1][1] = a;
    max_d[1][2] = min_d[1][2] = b;
    max_d[1][3] = min_d[1][3] = c;

    for(int i = 2; i <= n; i++){
        cin >> a >> b >> c; // 매번 한 줄씩만 입력받음
        int cur = i % 2;
        int prev = (i - 1) % 2;

        // 최대값 갱신
        max_d[cur][1] = max(max_d[prev][1], max_d[prev][2]) + a;
        max_d[cur][2] = max({max_d[prev][1], max_d[prev][2], max_d[prev][3]}) + b;
        max_d[cur][3] = max(max_d[prev][2], max_d[prev][3]) + c;

        // 최소값 갱신
        min_d[cur][1] = min(min_d[prev][1], min_d[prev][2]) + a;
        min_d[cur][2] = min({min_d[prev][1], min_d[prev][2], min_d[prev][3]}) + b;
        min_d[cur][3] = min(min_d[prev][2], min_d[prev][3]) + c;
    }

    int last = n % 2;
    if (n == 1) last = 1; // n이 1일 때 예외 처리

    cout << max({max_d[last][1], max_d[last][2], max_d[last][3]}) << " "
         << min({min_d[last][1], min_d[last][2], min_d[last][3]});

    return 0;
}