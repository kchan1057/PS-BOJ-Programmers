#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func(int k, int start) { // start: 탐색 시작 위치
    if (k == m) { // m개의 숫자를 다 골랐다면 출력
        for (int i = 0; i < m; i++) 
            cout << arr[i] << " ";
        cout << '\n';
        return;
    }

    for (int i = start; i <= n; i++) { // start부터 숫자 선택
        arr[k] = i; // k번째 숫자를 i로 선택
        func(k + 1, i + 1); // 다음 숫자 선택 (i 이후부터 탐색)
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    func(0, 1); // 초기에는 1부터 시작
    return 0;
}
