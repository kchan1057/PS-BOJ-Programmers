#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int left = 1, right = 1, sum = 1, cnt = 0;
    while(left <= right){
        if(sum < n){
            right++;
            sum += right;
        }
        else {
            if(sum == n) cnt++;
            sum -= left;
            left++;
        }
    }
    return cnt;
}