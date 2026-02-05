#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        long long k, cnt = 0; cin >> k;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i = 0; i < k; i++){
            int a; cin >> a;
            pq.push(a);
        }
        while(pq.size() != 1){
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            cnt += (a+b);
            pq.push(a+b);
        }
        cout << cnt << '\n';
    }
    return 0;
}