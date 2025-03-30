#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> li; // 각 톱니바퀴의 상태를 저장하는 문자열 벡터
vector<pair<int, int>> stack; // 회전할 톱니바퀴의 번호와 방향을 저장하는 스택 역할의 벡터
vector<int> visited; // 방문 여부를 체크하는 배열 (이미 회전 고려했는지 여부)

// 회전 가능 여부를 확인하는 재귀 함수
void check_rotation(int current_num, int current_dir)
{
    // 왼쪽 톱니바퀴가 존재하고 아직 방문하지 않은 경우
    if (current_num - 1 >= 0 && visited[current_num - 1] == 0)
    {
        // 현재 톱니의 6번 index와 왼쪽 톱니의 2번 index가 다르면 회전 가능
        if (li[current_num][6] != li[current_num - 1][2])
        {
            stack.push_back(make_pair(current_num - 1, current_dir * -1)); // 반대 방향으로 회전
            visited[current_num - 1] = 1; // 방문 처리
            check_rotation(current_num - 1, current_dir * -1); // 재귀 호출
        }
    }

    // 오른쪽 톱니바퀴가 존재하고 아직 방문하지 않은 경우
    if (current_num + 1 < li.size() && visited[current_num + 1] == 0)
    {
        // 현재 톱니의 2번 index와 오른쪽 톱니의 6번 index가 다르면 회전 가능
        if (li[current_num][2] != li[current_num + 1][6])
        {
            stack.push_back(make_pair(current_num + 1, current_dir * -1)); // 반대 방향으로 회전
            visited[current_num + 1] = 1; // 방문 처리
            check_rotation(current_num + 1, current_dir * -1); // 재귀 호출
        }
    }
}

int main()
{
    int t; // 톱니바퀴의 개수
    int k; // 회전 횟수

    cin >> t; // 톱니바퀴의 개수 입력

    li.resize(t); // 톱니바퀴 개수에 맞게 벡터 크기 조정
    for (int i = 0; i < t; ++i)
        cin >> li[i]; // 각 톱니바퀴의 상태 입력

    cin >> k; // 회전 명령 개수 입력
    for (int i = 0; i < k; ++i)
    {
        int num, direction; // num: 회전시킬 톱니바퀴 번호, direction: 회전 방향

        cin >> num >> direction; // 회전 명령 입력
        stack.clear(); // 이전 회전 정보 초기화
        stack.push_back(make_pair(num - 1, direction)); // 현재 회전 명령 스택에 넣기
        visited.assign(t, 0); // 방문 배열 초기화
        visited[num - 1] = 1; // 현재 톱니바퀴 방문 처리
        check_rotation(num - 1, direction); // 회전 가능한 인접 톱니 확인

        // 회전 명령을 하나씩 꺼내어 실제 회전 수행
        while (!stack.empty())
        {
            pair<int, int> top = stack.back(); // 스택에서 하나 꺼냄
            stack.pop_back();
            int tmp_num = top.first;  // 회전할 톱니바퀴 번호
            int tmp_dir = top.second; // 회전 방향

            if (tmp_dir == 1)
            { // 시계 방향 회전: 마지막 문자를 맨 앞으로 이동
                li[tmp_num] = li[tmp_num].back() + li[tmp_num].substr(0, 7);
            }
            else
            { // 반시계 방향 회전: 첫 문자를 맨 뒤로 이동
                li[tmp_num] = li[tmp_num].substr(1) + li[tmp_num][0];
            }
        }
    }

    int cnt = 0; // 12시 방향에 S극('1')인 톱니바퀴 개수 세기 위한 변수
    for (int i = 0; i < t; ++i)
    {
        if (li[i][0] == '1') // 12시 방향이 S극이면 카운트 증가
        {
            cnt++;
        }
    }

    cout << cnt << endl; // 결과 출력

    return 0; // 프로그램 종료
}
