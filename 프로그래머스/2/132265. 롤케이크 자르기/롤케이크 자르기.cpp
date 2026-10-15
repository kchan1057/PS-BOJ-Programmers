#include <string>
#include <vector>
using namespace std;

int solution(vector<int> topping) {
    int rightCnt[10001] = {};
    bool leftUsed[10001] = {};

    int leftKinds = 0;
    int rightKinds = 0;
    int ans = 0;

    for (int x : topping) {
        if (rightCnt[x] == 0) rightKinds++;
        rightCnt[x]++;
    }

    for (int x : topping) {
        if (!leftUsed[x]) {
            leftUsed[x] = true;
            leftKinds++;
        }

        rightCnt[x]--;
        if (rightCnt[x] == 0) {
            rightKinds--;
        }

        if (leftKinds == rightKinds) {
            ans++;
        }
    }

    return ans;
}