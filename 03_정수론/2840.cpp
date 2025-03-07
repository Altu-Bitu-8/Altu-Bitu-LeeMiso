#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<char> arr(N, '?'); // ������ ĭ (�ʱ⿡�� ��� '?')
    int pointer = 0; // ȭ��ǥ ��ġ

    for (int i = 0; i < K; i++) {
        int S;
        char ch;
        cin >> S >> ch;

        // ���� ȭ��ǥ�� ����Ű�� ��ġ �̵�
        pointer = (pointer - S % N + N) % N;

        // �̹� ä���� ĭ�� �ٸ� ���ڰ� ���´ٸ� ��� -> "!" ��� �� ����
        if (arr[pointer] != '?' && arr[pointer] != ch) {
            cout << "!" << endl;
            return 0;
        }
        
        // ���� ���ڰ� �� �� �̻� �����ϸ� ��� -> "!" ��� �� ����
        for (int j = 0; j < N; j++) {
            if (arr[j] == ch && j != pointer) {
                cout << "!" << endl;
                return 0;
            }
        }

        arr[pointer] = ch;
    }

    for (int i = 0; i < N; i++) {
        cout << arr[(pointer + i) % N];
    }
    cout << endl;

    return 0;
}