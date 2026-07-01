#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> e) {
    unordered_set<int> st;
    for(int i = 0; i < e.size(); i++){
        int sum = 0;
        for(int j = i; j < e.size() + i; j++){
            sum += e[j%e.size()];
            st.insert(sum);
        }
    }
    return st.size();
}