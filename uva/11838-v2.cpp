#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;

struct SCC
{
	vvi graph, rev_graph;
	vi order, components;
	vb vis;

	SCC(int n) : graph(n+1), rev_graph(n+1), vis(n+1) { }

	void add_edge(int u, int v)
	{
		graph[u].push_back(v);
		rev_graph[v].push_back(u);
	}

	void calc_order(int u)
	{
		vis[u] = true;
		for (auto v : graph[u])
			if (not vis[v]) calc_order(v);
		order.push_back(u);
	}

	void calc_scc(int u)
	{
		vis[u] = true;
		components.push_back(u);

		for (auto v : rev_graph[u])
			if (not vis[v]) calc_scc(v);
	}

	int print_scc()
	{
		vis.assign(vis.size(), false);
		order.clear();
		for (int i = 1; i < graph.size(); i++)
			if (not vis[i]) calc_order(i);

		int ans = 0;


		vis.assign(vis.size(), false);
		reverse(order.begin(), order.end());
		for (auto v : order)
			if (not vis[v])
			{
				components.clear();
				calc_scc(v);
				ans++;

				//for (auto n : components)
				//	cout << n << ' ';
				//cout << endl;
			}

		return ans == 1;
	}
};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int n, m;
	while (cin >> n >> m, n or m)
	{
		SCC scc(n);
		for (int i = 0; i < m; i++)
		{
			int u, v, p;
			cin >> u >> v >> p;

			if (p == 1) scc.add_edge(u, v);
			else scc.add_edge(u, v), scc.add_edge(v, u);
		}

		cout << scc.print_scc() << endl;
	}

	return 0;

}