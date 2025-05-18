// 14503: 로봇 청소기 (골드5/구현, 시뮬레이션)
#include <iostream>

using namespace std;

const int SIZE = 50; // 최대 방의 크기
const int CLEAN = 2; // 청소 완료 표시
int n, m, cnt = 0; // 세로 크기, 가로 크기, 청소한 칸 개수

int board[SIZE][SIZE]; // (0: 빈 칸, 1: 벽, 2: 청소 완료)
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0}; // 북 동 남 서

// 방향: 0(북), 1(동), 2(남), 3(서)
void dfs(int row, int col, int dir) {
    // 1. 현재 위치 청소
    if(board[row][col] != CLEAN) { // 아직 청소되지 않았다면
        cnt++; // 청소한 칸 수 증가
    }
    board[row][col] = CLEAN; // 현재 칸 청소 완료로 표시

    // [현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는가]
    // 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
    for(int i = 0; i < 4; i++) { // 3-1. 반시계 방향으로 90º 회전
        int new_dir = (dir-i+3) % 4; // 현재 방향에서 반시계로 회전한 방향 계산
        int new_row = row + dy[new_dir], new_col = col + dx[new_dir]; // 회전한 방향 기준 전진 위치

        if(board[new_row][new_col] == 0) { // 3-2. 아직 청소되지 않은 빈 칸 발견
            dfs(new_row, new_col, new_dir); // 한 칸 전진
            return; // 이후 처리는 중단
        }
    }

    // 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
    int back_dir = (dir+2) % 4; // 뒤쪽 방향 계산
    int back_row = row + dy[back_dir], back_col = col + dx[back_dir]; // 후진할 위치 계산

    // [바라보는 방향을 유지한 채로 한 칸 후진할 수 있는가]
    // 2-2. 뒤쪽 칸이 벽이라 후진할 수 없는 경우
    if(board[back_row][back_col] == 1) { // 벽이면 후진 불가
        return; // 작동 종료
    }
    // 2-1. 바라보는 방향을 유지한 채로 한 칸 후진
    dfs(back_row, back_col, dir); // 방향 유지한 채 후진하며 재귀 호출
    return;
}


int main() {
    int r, c, d; // 로봇 청소기 정보

    // 입력
    cin >> n >> m; // 방의 크기 입력
    cin >> r >> c >> d; // 로봇의 시작 위치 및 방향 입력

    for(int i = 0; i < n; i++) { // 방의 각 칸 입력
        for(int j = 0; j < m; j++) {
            cin >> board[i][j]; // 0: 빈 칸, 1: 벽
        }
    }

    // 연산
    dfs(r, c, d);

    // 출력
    cout << cnt;
    
    return 0;
}
