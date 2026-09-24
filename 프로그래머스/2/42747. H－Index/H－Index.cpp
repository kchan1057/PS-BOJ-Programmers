#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> c) {
    int ans = 0;

    for (int i = 0; i <= c.size(); i++) {
        int b = 0;

        for (int j = 0; j < c.size(); j++) {
            if (c[j] >= i) b++;
        }

        if (b >= i) ans = i;
    }

    return ans;
}