#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define maxn 10000

int graph[maxn];
int parent_arr[maxn];

struct Edge
{
	int from, to, cost;

	Edge(int _from, int _to, int _cost) 
	{
		from = _from;
		to = _to;
		cost = _cost;
	}

	bool operator< (const Edge &r) const
	{
		return r.cost < cost;
	}
};

int main(void)
{
	int cases;
	while(cin >> cases)
	{
		if(cases == 0)
			break;
		while(cases--)
		{
			int n, m;
			int cost = 0;
			vector<Edge> edges;
			cin >> n >> m;

			for(int i = 0; i < m; i++)
			{
				int a, b, c;
				cin >> a >> b >> c;
				edges.push_back(Edge(a, b, c));
			}

			sort(edges.begin(), edges.end());

			memset(parent_arr, -1, sizeof(parent_arr));

			for(int i = 0; i < m; i++)
			{
				if(parent_arr[edges[i].to] != -1)
				{
					cost += edges[i].cost;
					continue;
				}

				else if(parent_arr[edges[i].to] == -1)
				{
					parent_arr[edges[i].to] = edges[i].from;
					while(parent_arr[parent_arr[edges[i].to]] >= 0)
					{
						parent_arr[edges[i].to] = parent_arr[parent_arr[edges[i].to]];
					}
					parent_arr[parent_arr[edges[i].to]]--;
				}
			}

			cout << cost << endl;
		}
	}
	return 0;
}