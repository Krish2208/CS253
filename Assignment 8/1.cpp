#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> convert(vector<vector<int>> a)
{
    vector<vector<int>> adjList(a.size());
    for (int i = 0; i < a.size(); i++)
    {

        for (int j = 0; j < a[i].size(); j++)
        {
            if (a[i][j] == 1)
            {
                adjList[i].push_back(j);
            }
        }
    }
    return adjList;
}
void dfs(vector<vector<int>> &adj, vector<bool> &visit, int start)
{
    cout << start << " ";
    visit[start] = true;
    for (int i = 0; i < adj[start].size(); i++)
    {
        if (adj[start][i] == 1 && (!visit[i]))
            dfs(adj, visit, i);
    }
}
void bfs(vector<vector<int>> &adj, vector<bool> &visit, int start)
{
    vector<int> q;
    q.push_back(start);
    visit[start] = true;
    int vis;
    while (!q.empty())
    {
        vis = q[0];
        cout << vis << " ";
        q.erase(q.begin());
        for (int i = 0; i < adj[vis].size(); i++)
        {
            if (adj[vis][i] == 1 & (!visit[i]))
            {
                q.push_back(i);
                visit[i] = true;
            }
        }
    }
}
int main()
{
    vector<vector<int>> a;
    vector<int> p({0, 1, 0, 1, 1, 1});
    vector<int> q({1, 0, 1, 0, 0, 0});
    vector<int> r({0, 1 , 0, 1, 0, 0});
    vector<int> s({1, 0, 1, 0, 0, 0});
    vector<int> t({1, 0, 0, 0, 0, 0});
    vector<int> u({1, 0, 0, 0, 0, 0});
    a.push_back(p);
    a.push_back(q);
    a.push_back(r);
    a.push_back(s);
    a.push_back(t);
    a.push_back(u);
    vector<vector<int>> AdjList = convert(a);
    for (int i = 0; i < AdjList.size(); i++)
    {
        for (int j = i; j < AdjList[i].size(); j++)
        {
            cout << i;
            cout << "--" << AdjList[i][j] << endl;
        }
    }
    cout << "Depth First Search : ";
    vector<bool> visit(6, false);
    vector<bool> visit2(6, false);
    dfs(a, visit, 0);
    cout << "\nBreadth First Search : ";
    bfs(a, visit2, 0);
}