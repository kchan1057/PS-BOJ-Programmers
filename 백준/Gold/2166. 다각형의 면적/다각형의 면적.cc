#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // 입력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // pair<x, y> 형태로 좌표 저장
    vector<pair<long long, long long>> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i].first >> p[i].second;
    }

    double area = 0;

    // 신발끈 공식 적용
    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        // (x1*y2 + x2*y3 + ... + xn*y1) - (y1*x2 + y2*x3 + ... + yn*x1)
        area += (double)p[i].first * p[j].second;
        area -= (double)p[j].first * p[i].second;
    }

    // 결과값의 절대값 취하고 2로 나누기
    area = abs(area) / 2.0;

    // 소수점 첫째 자리까지 고정 출력
    cout << fixed << setprecision(1) << area << "\n";

    return 0;
}