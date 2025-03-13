#include <iostream>

using namespace std;

int main() {
    int e, s, m;
    int ans = 0;

    //입력
    cin >> e >> s >> m;

    //가장 큰 주기를 기준으로 하나하나 넣어보기
    for (int i = 0; ; i++) {
        ans = 28*i + s; 
        if ((ans-m) % 19 != 0) continue;
        if ((ans-e) % 15 != 0) continue;
        break;
    }
    
    //출력
    cout << ans << "\n";
    return 0;
}