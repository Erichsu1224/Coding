#include <iostream>	
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
#define maxn 510
#define INF 1e18

struct Edge
{
	int from, to, dist;
};

struct Item
{
	int d, u;
	bool operator <(const Item& rs) const
	{
		return d > rs.d;
	}
};

class dijkstra
{
private:
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool visited[maxn];
	int d[maxn];
	int p[maxn];
	









public:
	void AddEdge(int from, int to, int dist)
	{
		edges.push_back()
	}


	for(int i = 0; )
}