#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

const int MAX = 1000000000;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[101][101];
int check[101][101];

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int n, m;
    n = maps.size();
    m = maps[0].size();
    
    for(int y = 0; y < n; y++)
        for(int x = 0; x < m; x++)
        {
            board[y+1][x+1] = maps[y][x];
            check[y+1][x+1] = MAX;
        }
            

    queue<pair<int, int>> qu;
    qu.push({1, 1});
    check[1][1] = 1;
    
    while(!qu.empty())
    {
        pair<int, int> cur = qu.front();
        qu.pop();
        
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.second + dx[dir];
            int ny = cur.first + dy[dir];
            
            if(nx < 0 || ny < 0 || nx > m || ny > n)
                continue;
            if(board[ny][nx] == 0)
                continue;
            if(check[ny][nx] != MAX)
                continue;
            
            qu.push({ny, nx});
            check[ny][nx] = check[cur.first][cur.second] + 1;
        }
    }
    
    
    if(check[n][m] == MAX)
        answer = -1;
    else
        answer = check[n][m];
    
    return answer;
}