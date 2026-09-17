#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int len = begin.length();

    // {현재 단어, 현재까지의 변환 횟수}
    queue<pair<string, int>> Q;
    Q.push({begin, 0});

    vector<bool> vis(words.size(), false);

    while (!Q.empty()) {
        string cur = Q.front().first;
        int dist = Q.front().second;
        Q.pop();

        if (cur == target) {
            return dist;
        }

        for (int j = 0; j < words.size(); j++) {
            if (vis[j]) continue;

            int diff = 0;

            for (int i = 0; i < len; i++) {
                if (cur[i] != words[j][i]) {
                    diff++;
                }
            }

            if (diff == 1) {
                vis[j] = true;
                Q.push({words[j], dist + 1});
            }
        }
    }
    return 0;
}