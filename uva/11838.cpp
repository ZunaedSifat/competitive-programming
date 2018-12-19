#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;


void dfs(vvi &graph, int u, vector <bool> &vis)
{
    vis[u] = true;
    for (auto v : graph[u])
        if (not vis[v]) dfs(graph, v, vis);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n, m;
    while (cin >> n >> m, n or m)
    {
        vvi graph(n+1), rev_graph(n+1);
        vector <bool> vis(n+1), rev_vis(n+1);

        int u, v, p;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> p;
            if (p == 1) graph[u].push_back(v),
                rev_graph[v].push_back(u);
            else graph[u].push_back(v),
                 graph[v].push_back(u),
                 rev_graph[u].push_back(v),
                 rev_graph[v].push_back(u);
        }


        dfs(graph, 1, vis);
        dfs(rev_graph, 1, rev_vis);

        cout << (count(vis.begin(), vis.end(), true) == n and
             count(rev_vis.begin(), rev_vis.end(), true)  == n) << endl;
    }


    return 0;
}
