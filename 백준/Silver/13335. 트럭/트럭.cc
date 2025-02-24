#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <deque>

using namespace std;

queue<int> truck;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, W, L; // 트럭수, 다리 길이, 최대 하중
    cin >> N >> W >> L;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;

        truck.push(temp);
    }

    deque<pair<int, int>> bridge;
    int totalTime = 1;
    int curWeight = truck.front();
    bridge.push_back({ truck.front(), 1 });
    truck.pop();

    while (!(truck.empty() && bridge.empty()))
    {
        // 시간증가
        totalTime++;

        // 다리 위 트럭 위치 변경
        for (auto& cur : bridge)
        {
            cur.second += 1;
        }
       
        // 다 건너간 트럭 다리에서 제거
        while (!bridge.empty())
        {
            if (bridge.front().second > W)
            {
                curWeight -= bridge.front().first;
                bridge.pop_front();
            }

            if (bridge.empty())
                break;
            if (bridge.front().second <= W)
                break;
        }
         

        // 트럭 추가 가능하면 추가
        if (truck.empty())
            continue;

        if (curWeight + truck.front() <= L && bridge.size() < W)
        {
            curWeight += truck.front();
            bridge.push_back({ truck.front(), 1 });
            truck.pop();
        }
    }
    
    cout << totalTime;

    return 0;
}