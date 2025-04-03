#include <iostream>
#include <deque>
using namespace std;

deque<int> do_card, su_card;
deque<int> do_ground, su_ground;

void print_deque(const deque<int>& dq, const string& name) {
    cout << name << ": ";
    for (size_t i = 0; i < dq.size(); ++i) {
        cout << dq[i] << " ";  // 덱의 각 요소 출력
    }
    cout << endl;
}

void bell() {
    if (do_ground.back() == 5 || su_ground.back() == 5) {
        // 도도가 종을 쳤을 때
        while (!do_ground.empty()) {
            su_card.push_back(do_ground.front());
            do_ground.pop_front();
        }
        while (!su_ground.empty()) {
            su_card.push_back(su_ground.front());
            su_ground.pop_front();
        }
    } else if (!do_ground.empty() && !su_ground.empty() && (do_ground.back() + su_ground.back() == 5)) {
         // 수연이가 종을 쳤을 때
         while (!su_ground.empty()) {
            do_card.push_back(su_ground.front());
            su_ground.pop_front();
        }
        while (!do_ground.empty()) {
            do_card.push_back(do_ground.front());
            do_ground.pop_front();
        }
    }
}

string whoWins(int m) {
    if (do_card.size() == 0) {
        return "su";  // 도도의 덱이 비면 수연이가 승리
    }
    if (su_card.size() == 0) {
        return "do";  // 수연이의 덱이 비면 도도가 승리
    }
    if (m == 0) {
        if (do_card.size() > su_card.size()) {
            return "do";  // 도도가 승리
        } else if (do_card.size() < su_card.size()) {
            return "su";  // 수연이가 승리
        } else {
            return "dosu";  // 비김
        }
    }
    return "";
}


int main() {
    int N, M;
    cin >> N >> M;

    // 카드 덱 입력받기
    for (int i = 0; i < N; ++i) {
        int card;
        cin >> card;
        do_card.push_back(card);  // 도도 덱
   
        cin >> card;
        su_card.push_back(card);  // 수연 덱
    }
    print_deque(do_card, "do_card");
    print_deque(su_card, "su_card");

    while (M--) {
        // 도도 차례
        if (!do_card.empty()) {
            do_ground.push_back(do_card.front());
            do_card.pop_front();
        }

        if (do_card.empty() || su_card.empty()) {
            break;
        }

        bell();

        // 수연 차례
        if (!su_card.empty()) {
            su_ground.push_back(su_card.front());
            su_card.pop_front();
        }

        if (do_card.empty() || su_card.empty()) {
            break;
        }

        bell();
        print_deque(do_card, "do_card");
        print_deque(su_card, "su_card");

    }

    string result = whoWins(M);
    if (result == "") {
        cout << "dosu" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
