#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    vector<int> score;
    int i = 0;
    while (i < dartResult.size()) {
        int num = 0;

        if (dartResult[i] == '1' && i + 1 < dartResult.size() && dartResult[i + 1] == '0') {
            num = 10;
            i += 2;
        } else {
            num = dartResult[i] - '0';
            i++;
        }

        char bonus = dartResult[i++];

        if (bonus == 'D') {
            num *= num;
        } else if (bonus == 'T') {
            num = num * num * num;
        }

        if (i < dartResult.size() &&
            (dartResult[i] == '*' || dartResult[i] == '#')) {

            if (dartResult[i] == '*') {
                num *= 2;

                if (!score.empty()) {
                    score.back() *= 2;
                }
            } else {
                num *= -1;
            }

            i++;
        }

        score.push_back(num);
    }

    int answer = 0;

    for (int x : score) {
        answer += x;
    }

    return answer;
}