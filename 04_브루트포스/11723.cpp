#include <iostream>
#include <string>

using namespace std;

 // 전역변수를 쓰지 않고 코드를 짜기 어려워서 피드백 주시면 감사드리겠습니다..!
const int MAX_NUM = 20;
int s[MAX_NUM] = {0};

void add(int x) { 
    s[x - 1] = 1; 
} 

void remove(int x) { 
    s[x - 1] = 0; 
}

void check(int x) {
    cout << s[x - 1] << "\n"; 
}

void toggle(int x) { 
    s[x - 1] = 1 - s[x - 1]; 
}

void all() { 
    fill(s, s + MAX_NUM, 1); 
}

void empty() { 
    fill(s, s + MAX_NUM, 0); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, x;
    string cmd;

    cin >> m;

    while (m--) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> x;
            add(x);
        } 
        else if (cmd == "remove") {
            cin >> x;
            remove(x);
        } 
        else if (cmd == "check") {
            cin >> x;
            check(x);
        } 
        else if (cmd == "toggle") {
            cin >> x;
            toggle(x);
        } 
        else if (cmd == "all") {
            all();
        } 
        else if (cmd == "empty") {
            empty();
        }
    }
    return 0;
}