#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w) {
    int ct = stations[0], chk_len = 2*w+1;
    int ans = 0, len = ct - w - 1;
    if(len > 0 && len % chk_len != 0) ans += (len/chk_len) + 1;
    else ans += (len/chk_len);
    
    for(int i = 1; i < stations.size(); i++) {
        int post_ct = stations[i-1]+w, now_ct = stations[i] - w;
        int len = now_ct - post_ct - 1;
        if(len < 0 ) continue;
        if(len % chk_len != 0) ans += (len/chk_len) + 1;
        else ans += (len/chk_len);
    }
    
    int last_ct = stations[stations.size()-1] + w, last_start = n;
    int len1 = last_start - last_ct;
    if(len1 > 0 && len1 % chk_len != 0) ans += (len1/chk_len) + 1;
    else ans += (len1/chk_len);
    return ans;
}