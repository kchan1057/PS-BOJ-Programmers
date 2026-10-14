#include <string>
#include <vector>
#include <bitset>
using namespace std;


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> ans;
    for(int i = 0; i < n; i++) {
        int k = arr1[i] | arr2[i]; 
        string row = "";
        for(int j = n-1; j >= 0; j--){
            if(k & (1 << j)) row += '#';
            else row += ' ';
        }
        ans.push_back(row);
    }
    return ans;
}