#include <iostream>
#include <vector>

using namespace std;

void makeWheel(int n, int k, vector<pair<int,char>> &wheel) {
    vector<char> arr(n, '?'); // 諛뷀�댁쓽 移� (珥덇린�뿉�뒗 紐⑤몢 '?')
    int pointer = 0; // �솕�궡�몴 �쐞移�

    for (int i = 0; i < k; i++) {
        int s=wheel[i].first;
        char ch=wheel[i].second;

        // �쁽�옱 �솕�궡�몴媛� 媛�由ы궎�뒗 �쐞移� �씠�룞
        pointer = (pointer - s % n + n) % n;

        // �씠誘� 梨꾩썙吏� 移몄뿉 �떎瑜� 臾몄옄媛� �뱾�뼱�삩�떎硫� 紐⑥닚 -> "!" 異쒕젰 �썑 醫낅즺
        if (arr[pointer] != '?' && arr[pointer] != ch) {
            cout << "!" << endl;
            return;
        }
        
        // 媛숈�� 湲��옄媛� �몢 踰� �씠�긽 �벑�옣�븯硫� 紐⑥닚 -> "!" 異쒕젰 �썑 醫낅즺
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