#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int zero_cnt = 0, success_cnt = 0;
    sort(win_nums.begin(), win_nums.end());
    for(int i = 0; i < lottos.size(); i++) {
        if(lottos[i] == 0) zero_cnt++;
        else{
            if(binary_search(win_nums.begin(), win_nums.end(), lottos[i])) success_cnt++;
        }
    }
    map<int, int> mp;
    for(int i = 1; i <= 6; i++) mp[7-i] = i;
    mp[0] = 6;
    return {mp[success_cnt+zero_cnt], mp[success_cnt]};
}