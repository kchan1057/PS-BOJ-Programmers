#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    vector<char> vc;
    string st = to_string(n);
    for(char k : st) vc.push_back(k);
    sort(vc.begin(), vc.end(), greater<>());
    string ans = "";
    for(char k : vc) ans += k;
    return stoll(ans);
}