#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<char> pre, inor, post;

class Node
{
public:
    Node(int _t)
    {
        t = _t;
    }

private:
    Node* lc = nullptr;
    Node* rc = nullptr;
    Node* p = nullptr;
    int t;

public:
    void traversal(int a)
    {
        if (t == 0)
            return;

        if (a == 0) // 전위
        {
            pre.push_back(t + 'A' - 1);
            lc->traversal(0);
            rc->traversal(0);
        }
        else if (a == 1) // 중위
        {
            lc->traversal(1);
            inor.push_back(t + 'A' - 1);
            rc->traversal(1);
        }
        else // 후위
        {
            lc->traversal(2);
            rc->traversal(2);
            post.push_back(t + 'A' - 1);
        }
    }

    void setC(Node& l, Node& r)
    {
        lc = &l;
        rc = &r;
    }

    void setP(Node& _p)
    {
        p = &_p;
    }
};

Node* v[30];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        v[i] = new Node(i);
    }

    for (int i = 0; i < n; i++)
    {
        char a, b, c;
        int t, lc, rc;
        cin >> a >> b >> c;

        t = a - 'A' + 1;

        if (b == '.')
            lc = 0;
        else
            lc = b - 'A' + 1;

        if (c == '.')
            rc = 0;
        else
            rc = c - 'A' + 1;

        v[t]->setC(*v[lc], *v[rc]);

        v[lc]->setP(*v[t]);
        v[rc]->setP(*v[t]);
    }

  
    for (int i = 0; i < 3; i++)
    {
        queue<Node*> qu;
        qu.push(v[1]);

        while (!qu.empty())
        {
            Node* n = qu.front();
            qu.pop();

            n->traversal(i);
        }
    }

    for (auto c : pre)
        cout << c;

    cout << '\n';

    for (auto c : inor)
        cout << c;

    cout << '\n';

    for (auto c : post)
        cout << c;

    return 0;
}
