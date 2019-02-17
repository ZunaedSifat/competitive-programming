#include <bits/stdc++.h>
using namespace std;


int n, l, timer;
vector<int> tin, tout;
vector <vector <int>> adj, up;

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }

    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, cn = 0;
    cin >> t;

    while (++cn <= t)
    {
        cin >> n;
        adj.clear();
        adj.resize(n);
        vector <bool> is_root(n, true);

        for (int i = 0; i < n; i++) {
            int q; cin >> q;
            for (int j = 0, val; j < q; j++)
                cin >> val, adj[i].push_back(val-1), is_root[val-1] = false;
        }


        int root;
        for (int i = 0; i < n; i++)
            if (is_root[i]) root = i;
        preprocess(root);

        cout << "Case " << cn << ":\n";
        int q, u, v; cin >> q;
        for (int i = 0; i < q; i++)
            cin >> u >> v,
            cout << lca(u-1, v-1)+1 << '\n';
    }

    return 0;
}

