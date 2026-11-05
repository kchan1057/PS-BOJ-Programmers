#include <string>
#include <algorithm>
using namespace std;

int solution(string s) {
    int ans = s.length();

    for (int len = 1; len <= s.length() / 2; len++) {
        string prev = s.substr(0, len);
        int count = 1;
        int compressLen = 0;

        for (int j = len; j < s.length(); j += len) {
            string cur = s.substr(j, len);

            if (prev == cur) {
                count++;
            }
            else {
                compressLen += prev.length();

                if (count > 1) {
                    compressLen += to_string(count).length();
                }

                prev = cur;
                count = 1;
            }
        }

        compressLen += prev.length();

        if (count > 1) {
            compressLen += to_string(count).length();
        }

        ans = min(ans, compressLen);
    }

    return ans;
}