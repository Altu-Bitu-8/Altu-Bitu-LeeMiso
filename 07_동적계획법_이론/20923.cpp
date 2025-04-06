#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards;
const int DO = 0, SU = 1; // 플레이어 상수 (도도: 0, 수연: 1)

/** 승리 판단하기 */
string judge(cards& deck) {
	int do_deck = deck[DO].size(); // 도도의 카드 수
	int su_deck = deck[SU].size(); // 수연의 카드 수
	if (do_deck > su_deck) {
		return "do"; // 도도가 더 많으면 도도 승
	}
	else if (do_deck < su_deck) {
		return "su"; // 수연이가 더 많으면 수연 승
	}
	return "dosu"; // 같으면 무승부
}

/** 그라운드에서 덱으로 카드 옮기기 */
void groundToDeck(deque<int>& deck, deque<int>& ground) {
	while (!ground.empty()) { // 그라운드에 카드가 남아있는 동안
		deck.push_back(ground.back()); // 그라운드의 마지막 카드를 덱 뒤로 이동
		ground.pop_back(); // 그라운드에서 해당 카드 제거
	}
}

/** 종을 쳤을 때 */
void ringTheBell(int player, cards& deck, cards& ground) {
	groundToDeck(deck[player], ground[!player]); // 상대 그라운드 → 본인 덱으로 카드 이동
	groundToDeck(deck[player], ground[player]);  // 본인 그라운드 → 본인 덱으로 카드 이동
}

/** 종을 울릴 수 있는 사람 판단 */
int whoCanRingTheBell(cards& deck, cards& ground) {
	// 도도의 그라운드 맨 위 카드가 5인 경우
	if (!ground[DO].empty() && ground[DO].front() == 5) {
		return DO; // 도도가 종을 칠 수 있음
	}
	// 수연의 그라운드 맨 위 카드가 5인 경우
	else if (!ground[SU].empty() && ground[SU].front() == 5) {
		return DO; // 도도가 종을 칠 수 있음
	}
	// 두 그라운드 맨 위 카드의 합이 5인 경우
	else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) {
		return SU; // 수연이가 종을 칠 수 있음
	}
	return -1; // 아무도 종을 칠 수 없음
}

/** 게임 진행 */
string game(int m, cards& deck, cards& ground) {
	bool turn = DO; // 도도가 먼저 시작

	while (m--) { // m번 라운드 반복
		// 현재 플레이어가 카드 1장 그라운드로 내려놓음
		ground[turn].push_front(deck[turn].front()); // 덱의 맨 앞 카드 → 그라운드 맨 앞
		deck[turn].pop_front(); // 덱에서 카드 제거

		// 덱이 비었으면 게임 종료
		if (deck[turn].empty()) {
			break;
		}

		// 종을 울릴 수 있는지 확인
		int bell = whoCanRingTheBell(deck, ground);
		if (bell != -1) { // 종을 울릴 수 있다면
			ringTheBell(bell, deck, ground); // 해당 플레이어가 종을 침
		}

		turn = !turn; // 다음 플레이어 차례로 전환
	}

	return judge(deck); // 최종 승자 판단 후 리턴
}

/**
 * 도도, 수연이 각각 덱과 그라운드를 가짐
 * 도도->수연->도도->수연... 순으로 차례를 바꿔가며 게임 진행 (game 함수)
 * 1. 카드를 덱에서 한 장 내려놓음
 * 2. 어떤 플레이어가 종을 칠 수 있는지 판단 (whoCanRingTheBell 함수)
 * 3. 종을 친 경우 그라운드의 카드를 덱으로 이동(ringTheBell, groundToDeck 함수)
 * 종료 조건 만족 시 승리한 사람 리턴(judge 함수)
 */

int main() {
	int n, m, card1, card2; // n: 카드 개수, m: 진행할 턴 수
	cards deck(2), ground(2); // 도도와 수연의 덱과 그라운드

	// 카드 입력 받기
	cin >> n >> m;
	while (n--) {
		cin >> card1 >> card2;
		deck[DO].push_front(card1); // 도도 덱의 앞쪽에 입력 (뒤집힌 상태)
		deck[SU].push_front(card2); // 수연 덱의 앞쪽에 입력 (뒤집힌 상태)
	}

	// 게임 실행 후 결과 출력
	cout << game(m, deck, ground);

	return 0;
}