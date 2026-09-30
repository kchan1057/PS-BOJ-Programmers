#include <vector>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int left = 0;
    int right = 0;
    long long sum = sequence[0];

    int bestLeft = 0;
    int bestRight = sequence.size() - 1;

    while (left <= right && right < sequence.size()) {

        if (sum == k) {
            // 더 짧은 구간이면 갱신
            if (right - left < bestRight - bestLeft) {
                bestLeft = left;
                bestRight = right;
            }

            // 더 짧은 구간이 있는지 보기 위해 왼쪽을 줄여봄
            sum -= sequence[left];
            left++;
        }

        else if (sum < k) {
            right++;

            if (right < sequence.size()) {
                sum += sequence[right];
            }
        }

        else { // sum > k
            sum -= sequence[left];
            left++;
        }
    }

    return {bestLeft, bestRight};
}