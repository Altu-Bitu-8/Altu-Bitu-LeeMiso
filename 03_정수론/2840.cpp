#include <iostream>
#include <vector>

using namespace std;

void makeWheel(int n, int k, vector<pair<int,char>> &wheel) {
    vector<char> arr(n, '?'); // ������ ĭ (�ʱ⿡�� ��� '?')
    int pointer = 0; // ȭ��ǥ ��ġ

    for (int i = 0; i < k; i++) {
        int s=wheel[i].first;
        char ch=wheel[i].second;

        // ���� ȭ��ǥ�� ����Ű�� ��ġ �̵�
        pointer = (pointer - s % n + n) % n;

        // �̹� ä���� ĭ�� �ٸ� ���ڰ� ���´ٸ� ��� -> "!" ��� �� ����
        if (arr[pointer] != '?' && arr[pointer] != ch) {
            cout << "!" << endl;
            return;
        }
        
        // ���� ���ڰ� �� �� �̻� �����ϸ� ��� -> "!" ��� �� ����
        for (int j = 0; j < n; j++) {
            if (arr[j] == ch && j != pointer) {
                cout << "!" << endl;
                return;
            }
        }

        arr[pointer] = ch;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[(pointer + i) % n];
    }
    cout << endl;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int,char>> wheel(k);
    for(int i=0; i<k;i++){
        cin>>wheel[i].first>>wheel[i].second;
    }

    makeWheel(n,k,wheel);
   
    return 0;
}