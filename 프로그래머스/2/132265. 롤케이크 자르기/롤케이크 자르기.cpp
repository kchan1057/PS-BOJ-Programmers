#include <string>
#include <vector>
#include <map>
using namespace std;
int arr[10002];
int solution(vector<int> topping) {
    int diff = 0, ans = 0;
    map<int, int> mp_left, mp_right;
    for(int i = 0; i < topping.size(); i++) mp_right[topping[i]]++;
    for(int i = 0; i < topping.size(); i++){
        mp_left[topping[i]]++; mp_right[topping[i]]--;
        if(mp_right[topping[i]] == 0) mp_right.erase(topping[i]);
        if(mp_left.size() == mp_right.size()) ans++;
    }
    return ans;
}