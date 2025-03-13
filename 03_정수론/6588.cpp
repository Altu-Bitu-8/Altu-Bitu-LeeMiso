#include <iostream>
#include <vector>

using namespace std;

vector<bool> findPrime(int n) {
    vector<bool> is_prime(n + 1, true); // 소수 여부 저장
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) continue; // flase 된 수는 스킵

        for (int j = i * 2; j <= n; j += i) {
            is_prime[j] = false; // 현재 수의 배수 false 처리 
        }
    }
    return is_prime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int MAX_N = 1000000;
    vector<bool> is_prime = findPrime(MAX_N); // 1000000까지의 소수를 미리 구함

    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        bool found = false;
        for (int a = n - 3; a >= 3; a -= 2) { // 가장 큰 홀수 소수부터 탐색
            int b = n - a;
            if (is_prime[a] && is_prime[b]) { // 두 수가 모두 소수인지 확인
                cout << n << " = " << b << " + " << a << "\n"; 
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
    return 0;
}