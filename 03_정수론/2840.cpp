#include <iostream>
#include <vector>

using namespace std;

void makeWheel(int n, int k, vector<pair<int,char>> &wheel) {
    vector<char> arr(n, '?');  // 바퀴의 칸 (초기에는 모두 '?')
    int pointer = 0;// 화살표 위치

    for (int i = 0; i < k; i++) {
        int s=wheel[i].first;
        char ch=wheel[i].second;

        // 현재 화살표가 가리키는 위치 이동
        pointer = (pointer - s % n + n) % n;

        // 이미 채워진 칸에 다른 문자가 들어온다면 모순 -> "!" 출력 후 종료
        if (arr[pointer] != '?' && arr[pointer] != ch) {
            cout << "!" << endl;
            return;
        }
        
        // 같은 글자가 두 번 이상 등장하면 모순 -> "!" 출력 후 종료
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