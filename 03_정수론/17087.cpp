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
    int n;
    long long s;
    cin >> n >> s;

    vector<long long> arr(n);  // �������� ��ġ�� ����
    vector<long long> diff(n); // �Ÿ� ���̸� ����

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        diff[i] = abs(arr[i] - s); // �� ������ S�� �Ÿ� ���� ����
    }

    // diff[0]�� �������� diff[i]���� �ִ����� ���ϱ�
    long long d = diff[0];
    for (int i = 1; i < n; i++) {
        d = getGcdRecur(d, diff[i]);
    }

    cout << d << endl;
    return 0;
}