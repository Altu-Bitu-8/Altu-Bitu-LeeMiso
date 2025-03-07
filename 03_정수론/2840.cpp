#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<char> arr(N, '?'); // 바퀴의 칸 (초기에는 모두 '?')
    int pointer = 0; // 화살표 위치

    for (int i = 0; i < K; i++) {
        int S;
        char ch;
        cin >> S >> ch;

        // 현재 화살표가 가리키는 위치 이동
        pointer = (pointer - S % N + N) % N;

        // 이미 채워진 칸에 다른 문자가 들어온다면 모순 -> "!" 출력 후 종료
        if (arr[pointer] != '?' && arr[pointer] != ch) {
            cout << "!" << endl;
            return 0;
        }
        
        // 같은 글자가 두 번 이상 등장하면 모순 -> "!" 출력 후 종료
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