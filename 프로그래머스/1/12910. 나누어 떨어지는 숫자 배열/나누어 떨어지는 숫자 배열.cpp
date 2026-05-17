#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> ans;
    for(auto k : arr){
        if(k % divisor == 0) ans.emplace_back(k);
    }
    if(ans.size() == 0) ans.emplace_back(-1);
    else sort(ans.begin(), ans.end());
    return ans;
}