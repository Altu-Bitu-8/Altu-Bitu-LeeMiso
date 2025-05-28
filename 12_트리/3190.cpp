#include <iostream> // 표준 입출력 사용
#include <vector>   // 2차원 배열 board 사용
#include <deque>    // 뱀 몸통 위치 추적용
#include <map>      // 시간별 방향 명령 저장용

using namespace std;
typedef pair<int, int> ci; // 좌표 표현용

const int EMPTY = 0; // 빈 칸
const int APPLE = 1; // 사과 칸
const int SNAKE = 2; // 뱀 칸

/**
 * 게임이 몇 초에 끝나는지 계산한다.
*/
int playGame(int n, vector<vector<int>> &board, map<int, char> &cmd) {
    // 동(→), 남(↓), 서(←), 북(↑)
    int dx[4] = {0, -1, 0, 1}; // 행 변화량 (북쪽이 -1)
    int dy[4] = {1, 0, -1, 0}; // 열 변화량 (동쪽이 +1)

    // 초기화
    deque<ci> snake; // 뱀의 위치 정보
    snake.push_front({1, 1}); // 뱀의 머리를 (1,1)에 위치
    board[1][1] = SNAKE; // 보드에 뱀 표시

    int time = 0; // 현재 시간
    int dir = 0;  // 현재 방향
    while (true) {
        // 방향 변환 정보가 있다면
        if (cmd[time] == 'L') { // 왼쪽 회전
            dir = (dir + 1) % 4; // 시계방향 기준 90도 회전
        } else if (cmd[time] == 'D') { // 오른쪽 회전
            dir = (dir + 3) % 4; // 시계방향 기준 -90도 회전
        }

        // 시간 증가
        time++;

        // 다음에 뱀의 머리가 위치하게 될 칸
        int nx = snake.front().first + dx[dir]; // 다음 행
        int ny = snake.front().second + dy[dir]; // 다음 열

        // 게임 종료 조건: 벽에 부딪히거나, 자기자신의 몸에 부딪힘
        if (nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny] == SNAKE) {
            break;
        }

        // 이동
        snake.push_front({nx, ny}); // 머리를 다음 칸에 위치시킴
        if (board[nx][ny] != APPLE) { // 이동한 칸에 사과가 없다면(몸길이가 그대로라면) 꼬리를 다음 칸에 위치시킴
            ci tail = snake.back(); // 꼬리 좌표 확인
            board[tail.first][tail.second] = EMPTY; // 꼬리 칸을 비움
            snake.pop_back(); // 꼬리 제거
        }
        board[nx][ny] = SNAKE; // 새 머리 위치에 뱀 표시
    }
    return time; // 종료 시간 반환
}

int main() {
    int n, k, x, y, l, time;
    char command;

    //입력
    cin >> n >> k; // 보드 크기와 사과 개수 입력
    vector<vector<int>> board(n + 1, vector<int>(n + 1, EMPTY)); // 1-based 인덱스를 위한 보드 초기화
    while (k--) {
        cin >> x >> y; // 사과 좌표 입력
        board[x][y] = APPLE; // 사과의 위치 표시
    }
    cin >> l; // 방향 변환 명령 개수
    map<int, char> cmd; // 명령어 저장용 맵
    while (l--) {
        cin >> time >> command; // 뱀의 방향 변환 정보
        cmd[time] = command; // 해당 시간에 명령 저장
    }

    // 연산 및 출력
    cout << playGame(n, board, cmd); // 게임 실행 및 종료 시간 출력
    return 0;
}
