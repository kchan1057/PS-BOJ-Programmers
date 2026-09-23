#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> arr) {
    vector<int> ans;
    int m = *max_element(arr.begin(), arr.end());
    while(1) {
        bool chk = true;
        for(int k : arr){
            if(k != 1) chk = false;
        }
        if(chk) break;
        
        for(int i = 2; i <= m; i++){
            bool chk2 = false;
            for(int j = 0; j < arr.size(); j++){
                if(arr[j] % i == 0) {
                    arr[j] /= i;
                    chk2 = true;
                }
            }
            if(chk2) {
                ans.push_back(i);
                break;
            }
        }
        
    }
    
    
    int sum = 1;
    for(int k : ans) sum *= k;
    
    return sum;
}