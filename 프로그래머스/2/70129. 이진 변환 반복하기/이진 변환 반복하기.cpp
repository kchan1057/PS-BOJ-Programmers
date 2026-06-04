#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> ans;
    int ch = 0, cnt = 0;
    while(s != "1"){
        string cpy = "";
        for(auto k : s){
            if(k == '0') cnt++;
            else cpy += k;
        }
        int num = cpy.length();
        string mid = "";
        do {
            mid += to_string(num%2);
        } while(num /= 2);
        reverse(mid.begin(), mid.end());
        s = mid;
        ch++;
    }
    ans.push_back(ch);
    ans.push_back(cnt);
    return ans;
}