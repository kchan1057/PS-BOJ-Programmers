#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> chk(n+1, 0);
    sort(lost.begin(), lost.end());
    for(int i = 0; i < reserve.size(); i++) chk[reserve[i]] = 1;
    for(int i = 0; i < lost.size(); i++){
        if(chk[lost[i]] == 1) chk[lost[i]] = 0;
        else chk[lost[i]] = -1;
    }
    int ans = 0;
    for(int i = 0; i < lost.size(); i++){
        int k = lost[i];
        if(chk[k] == -1) {
            if(k-1 > 0 && chk[k-1] == 1) {
                chk[k] = 0;
                chk[k-1] = 0;
            }
            else if(k+1 <= n && chk[k+1] == 1) {
                chk[k] = 0;
                chk[k+1] = 0;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(chk[i] == -1) ans++;
    }
    return n - ans;
}