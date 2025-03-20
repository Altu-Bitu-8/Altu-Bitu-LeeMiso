#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> heap; // 최소 힙 사용

    for (int i = 0; i < n; i++) { // n개의 값을 큐에 삽입
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            if (heap.size() < n) { // 큐 크기가 N보다 작으면 삽입
                heap.push(num);
            } 
            else if (num > heap.top()) { // 새로운 값이 현재 최소 힙의 최솟값보다 크면 교체
                heap.pop();
                heap.push(num);
            }
        }
    }

    // 최종적으로 남은 N개의 숫자 중 가장 작은 값이 N번째 큰 수
    cout << heap.top() << "\n";

    return 0;
}
