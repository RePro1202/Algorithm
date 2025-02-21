#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int check[101];


int solution(int n, vector<vector<int>> wires) {
    int answer = 1000000000;
    
    for(int i = 0; i < wires.size(); i++)
    {
        fill(check, check + 101, 0);
        
        vector<int> edge[101];
        
        for(int j = 0; j < wires.size(); j++)
        {
            if(i == j)
                continue;
            
            int x = wires[j][0];
            int y = wires[j][1];
            
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        
        queue<int> qu;
        qu.push(1);
        check[1] = 1;
        
        int count = 1;
        while(!qu.empty())
        {
            int cur = qu.front();
            qu.pop();
            
            if(edge[cur].empty())
                continue;
            
            for(auto a : edge[cur])
            {
                if(check[a] != 0)
                    continue;
                
                check[a] = 1;
                qu.push(a);
                
                count++;
            }
        }
        
        if(abs((n-count)-count) < answer)
            answer = abs((n-count)-count);
        
    }
    
    
    return answer;
}