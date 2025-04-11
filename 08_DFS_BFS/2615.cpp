#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix; // 2차원 벡터
const int SIZE = 20, EMPTY = 0; // 바둑판 크기와 빈 칸 값 정의

// 방향에 따른 x, y 증가량
// 맨 왼쪽 위 돌을 기준으로 검사하기 때문에 오른쪽+아래쪽으로 향하는 방향만 정의
const vector<int> dx = {-1, 0, 1, 1}; // x 좌표 변화량
const vector<int> dy = {1, 1, 1, 0};  // y 좌표 변화량

/**
 * 범위와 돌의 종류가 유효한지 확인한다.
*/
bool isValid(matrix &board, int x, int y, int color) {
    return (x > 0 && x < SIZE && y > 0 && y < SIZE && board[x][y] == color);
}

/**
 * 해당 좌표(x, y)부터 연속적으로 5알이 놓이는지 확인한다.
*/
bool checkWin(matrix &board, int x, int y) {
    int color = board[x][y]; // 현재 위치의 돌 색상 저장

    // 4가지 방향에 대해 검사
    for (int idx = 0; idx < 4; idx++) {
        int cnt = 1;  // 연속된 같은 색 돌 개수 (현재 위치 포함)
        int prev_x = x - dx[idx], prev_y = y - dy[idx]; // 이전 위치 좌표 계산 (연속된 여섯 알 이상을 거르기 위해 사용)
        int next_x = x + dx[idx], next_y = y + dy[idx]; // 다음 위치 좌표 계산

        // 같은 방향에서 그 이전에도 같은 색 돌이 있었다면 패스 (-> 여섯 알 이상 놓이는 경우를 제외하기 위함)
        if (isValid(board, prev_x, prev_y, color)) {
            continue;
        }

        // 연속적으로 놓인 5알이 같은 색인지 확인
        while (isValid(board, next_x, next_y, color) && cnt < 6) {
            next_x += dx[idx]; // 다음 x 위치로 이동
            next_y += dy[idx]; // 다음 y 위치로 이동
            cnt++; // 연속된 돌 개수 증가
        }

        // cnt가 5일 때만 true 리턴 (-> 다섯 알보다 적거나 다섯 알보다 많이 놓이는 경우를 제외)
        if (cnt == 5) {
            return true;
        }
    }

    // 4방향 모두 검사 후에도 없으면 false
    return false;
}

int main() {
    // 입력
    matrix board(SIZE, vector<int>(SIZE, 0)); // 20x20 바둑판 초기화 (1~19까지만 사용)
    for (int i = 1; i < SIZE; i++) {
        for (int j = 1; j < SIZE; j++) {
            cin >> board[i][j]; // 각 칸에 놓인 돌 정보 입력
        }
    }

    // 바둑판을 전체 순회하면서 승리 여부 확인
    for (int y = 1; y < SIZE; y++) { // 행 기준
        for (int x = 1; x < SIZE; x++) { // 열 기준
            if (board[x][y] == EMPTY) { // 빈 칸이면 패스
                continue;
            }
            if (checkWin(board, x, y)) {  // 현재 칸을 시작으로 오목이 되었는지 확인
                cout << board[x][y] << '\n' // 승리한 돌 출력 (1 또는 2)
                     << x << ' ' << y;  // 시작 좌표 출력
                return 0; // 프로그램 종료
            }
        }
    }

    // 오목이 없으면 0 출력
    cout << 0;
    return 0;
}