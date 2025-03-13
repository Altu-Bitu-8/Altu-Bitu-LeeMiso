#include <iostream>
#include <map>
#include <vector>

using namespace std;

//체스판에 유효한 자리인지
bool isValid(int col, int row){
    if (col >= 'A' && col <= 'H' && row >= 1 && row <= 8) {
        return 1;
    }
    return 0;
}

//이동하는 함수
pair<char, int> move(pair<char, int> a, string cmd) {
    map<string, pair<int, int>> m = {
        {"R", {1, 0}}, {"L", {-1, 0}}, {"B", {0, -1}}, {"T", {0, 1}},
        {"RT", {1, 1}}, {"LT", {-1, 1}}, {"RB", {1, -1}}, {"LB", {-1, -1}}
    };
    
    char col = a.first + m[cmd].first;
    int row = a.second + m[cmd].second;
    
    if (isValid(col, row))
        return {col, row}; //유효하면 이동
    else
        return a; //유효하지 않다면 무효
}

int main(){

    pair<char, int> king, rock;
    int n;

    //입력
    cin >> king.first >> king.second >> rock.first >> rock.second >> n;
    vector<string> orders(n);

    for (int i = 0; i < n; i++) {
        cin >> orders[i];
    }

    //이동
    for (const string &cmd : orders) {
        pair<char, int> new_king = move(king, cmd);

        // 킹이 이동했을 때 돌과 겹치면 돌도 이동
        if (new_king == rock) {
            pair<char, int> new_rock = move(rock, cmd);
            if (new_rock != rock) { // 돌도 유효한 위치면 이동
                rock = new_rock;
                king = new_king;
            }
        } else {
            king = new_king;
        }
    }

    //출력
    cout << king.first << king.second << endl;
    cout << rock.first << rock.second << endl;

    return 0;
}