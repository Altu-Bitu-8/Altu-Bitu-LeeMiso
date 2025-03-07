#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�ִ����� ���ϱ� 
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

    vector<long long> arr(N);  // �������� ��ġ�� ����
    vector<long long> diff(N); // �Ÿ� ���̸� ����

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        diff[i] = abs(arr[i] - S); // �� ������ S�� �Ÿ� ���� ����
    }

    // diff[0]�� �������� diff[i]���� �ִ����� ���ϱ�
    long long D = diff[0];
    for (int i = 1; i < N; i++) {
        D = getGcdRecur(D, diff[i]);
    }

    cout << D << endl;
    return 0;
}