#include <iostream>
#include <vector>

using namespace std;

vector<bool> findPrime(int n) {
    vector<bool> is_prime(n + 1, true); // �Ҽ� ���� ����
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) continue; // flase �� ���� ��ŵ

        for (int j = i * 2; j <= n; j += i) {
            is_prime[j] = false; // ���� ���� ��� false ó�� 
        }
    }
    return is_prime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int MAX_N = 1000000;
    vector<bool> is_prime = findPrime(MAX_N); // 1000000������ �Ҽ��� �̸� ����

    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        bool found = false;
        for (int a = n - 3; a >= 3; a -= 2) { // ���� ū Ȧ�� �Ҽ����� Ž��
            int b = n - a;
            if (is_prime[a] && is_prime[b]) { // �� ���� ��� �Ҽ����� Ȯ��
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