#include <iostream>
#include <vector>

using namespace std;

// result 이상인 v의 배수 중 최소값을 구하는 함수
long long next_speed(long long v, long long result) {
    if (result % v == 0) {
        return result;
    }
    return (result / v + 1) * v;
}

int main() {
    int n;
    cin >> n;

    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    long long result = v[n - 1];

    // 역방향으로 순회하면서 조건 맞추기
    for (int i = n - 2; i >= 0; --i) {
        if (v[i] > result) {
            result = v[i];
        } 
        else {
            result = next_speed(v[i], result);
        }
    }

    cout << result << '\n';
    return 0;
}
