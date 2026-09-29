#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool isused[5];
vector<string> st;
vector<char> ch = {'A', 'E', 'I', 'O', 'U'};
void dfs(string k, vector<string>& st){
    if(k.length() == 5) return;
    
    for(int i = 0; i < 5; i++) {
        k += ch[i];
        st.push_back(k);
        dfs(k, st);
        k.erase(k.end()-1);
    }
    
}
int solution(string word) {
    dfs("", st);
    return find(st.begin(), st.end(), word) - st.begin()+1;
}