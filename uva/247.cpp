#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;


map <string, int> mp_si;
map <int, string> mp_is;


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

	void print_scc()
	{
		vis.assign(vis.size(), false);
		order.clear();
		for (int i = 1; i < graph.size(); i++)
			if (not vis[i]) calc_order(i);

		vis.assign(vis.size(), false);
		reverse(order.begin(), order.end());
		for (auto v : order)
			if (not vis[v])
			{
				components.clear();
				calc_scc(v);
				
				cout << mp_is[components.front()];
				for (int i = 1; i < components.size(); i++)
					cout << ", " << mp_is[components[i]];
				cout << '\n';
			}
	}
};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int n, m, cn = 0;
	while (cin >> n >> m, n or m)
	{
		if (cn) cout << '\n';

		SCC scc(n);

		int idx = 0;
		mp_is.clear();
		mp_si.clear();

		cout << "Calling circles for data set " << ++cn << ":\n";
		for (int i = 0; i < m; i++)
		{
			string u, v;
			cin >> u >> v;

			if (mp_si.count(u) < 1) mp_si[u] = ++idx, mp_is[idx] = u;
			if (mp_si.count(v) < 1) mp_si[v] = ++idx, mp_is[idx] = v;

			//cout << mp_si[u] << ' ' << mp_si[v] << endl;

			scc.add_edge(mp_si[u], mp_si[v]);
		}

		//cerr << idx << endl;

		scc.print_scc();
	}

	return 0;
}