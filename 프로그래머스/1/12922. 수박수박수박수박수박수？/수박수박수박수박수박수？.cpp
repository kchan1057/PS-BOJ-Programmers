#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string ans = "";
    vector<string> vc = {"수", "박"};
    for(int i = 0; i < n; i++) ans += vc[i%2];
    return ans;
}