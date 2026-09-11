#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int ans = 0;
    string st = "";
    for(int i = 0; i < p.length(); i++) st += t[i];
    
    for(int i = p.length(); i <= t.length(); i++){
        if(stoll(st) <= stoll(p)) ans++;
        st.erase(st.begin());
        st += t[i];
    }
    
    return ans;
}