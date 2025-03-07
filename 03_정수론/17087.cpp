#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//최대공약수 구하기 
int getGcdRecur(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGcdRecur(b, a % b);
}

int main() {
    int N;
    long long S;
    cin >> N >> S;

    vector<long long> arr(N);  // 동생들의 위치를 저장
    vector<long long> diff(N); // 거리 차이를 저장

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        diff[i] = abs(arr[i] - S); // 각 동생과 S의 거리 차이 저장
    }

    // diff[0]를 기준으로 diff[i]들의 최대공약수 구하기
    long long D = diff[0];
    for (int i = 1; i < N; i++) {
        D = getGcdRecur(D, diff[i]);
    }

    cout << D << endl;
    return 0;
}