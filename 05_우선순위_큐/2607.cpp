#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>

using namespace std;

// 두 단어의 구성 차이를 계산하는 함수
bool isSimilar(const vector<char> &word1, const vector<char> &word2) {
    map<char, int> freq1, freq2;
    
    for (char c : word1) {
        freq1[c]++;
    }
    for (char c : word2) {
        freq2[c]++;
    }
    
    int diff_count = 0;
    int more_count = 0, less_count = 0;
    
    for (char c = 'A'; c <= 'Z'; c++) {
        int diff = freq1[c] - freq2[c];
        if (diff > 0) more_count += diff;
        if (diff < 0) less_count -= diff;
    }
    
    if (more_count == 0 && less_count == 0) return true; // 같은 구성
    if ((more_count == 1 && less_count == 0) || (more_count == 0 && less_count == 1)) return true; // 한 글자 추가 또는 삭제
    if (more_count == 1 && less_count == 1) return true; // 한 글자 변경
    
    return false;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<char>> words(n);
    
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words[i] = vector<char>(word.begin(), word.end());
    }
    
    vector<char> first_word = words[0];
    int ans = 0;
    
    for (int i = 1; i < n; i++) {
        if (isSimilar(first_word, words[i])) {
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}

//우선순위 큐를 사용하는 방법이 떠오르지 않습니다....
//피드백을 주시거나 코드를 올려주시면 다시 공부해보도록 하겠습니다! 