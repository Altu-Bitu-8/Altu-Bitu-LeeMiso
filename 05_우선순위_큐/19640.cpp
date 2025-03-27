#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

// 우선순위 큐에서 사용할 정렬 기준
struct cmp {
    bool operator()(const tuple<int, int, int, int> &a, const tuple<int, int, int, int> &b) {
        if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b); // 근무 일수 기준 내림차순
        if (get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b); // 화장실 급한 정도 기준 내림차순
        return get<3>(a) > get<3>(b); // 줄 번호 기준 오름차순
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<queue<tuple<int, int, int>>> lines(m); // M개의 줄을 나타내는 큐
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, cmp> pq;

    int deka_pos = k; // 데카의 대기번호
    int count = 0; // 화장실 이용한 사람 수

    for (int i = 0; i < n; i++) {
        int d, h;
        cin >> d >> h;
        lines[i % m].push(make_tuple(i, d, h)); // 사원 각각의 대기번호, 근무 일수, 화장실 급함 정도
    }

    // 각 줄의 첫 번째 사람을 우선순위 큐에 삽입
    for (int i = 0; i < m; i++) {
        if (!lines[i].empty()) {
            tuple<int, int, int> front_person = lines[i].front();
            lines[i].pop();
            pq.push(make_tuple(get<0>(front_person), get<1>(front_person), get<2>(front_person), i));
        }
    }

    // 화장실 사용 진행
    while (!pq.empty()) {
        tuple<int, int, int, int> current = pq.top();
        pq.pop();
        count++;

        int num = get<0>(current);
        int d = get<1>(current);
        int h = get<2>(current);
        int line_idx = get<3>(current);

        // 데카의 대기번호와 비교하여 같으면 끝
        if (num == deka_pos) {
            cout << count - 1 << endl;
            return 0;
        }

        // 현재 줄에서 새로운 선두 우선순위 큐에 삽입
        if (!lines[line_idx].empty()) {
            tuple<int, int, int> next_person = lines[line_idx].front();
            lines[line_idx].pop();
            pq.push(make_tuple(get<0>(next_person), get<1>(next_person), get<2>(next_person), line_idx));
        }
    }
    return 0;
}