#include<iostream>
#include <vector>
#include<queue>

void addEdge(std::vector<int> a[], int u, int v)
{
	a[u].push_back(v);
	a[v].push_back(u);
}

void printAdj(std::vector<int> a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (auto x : a[i])
		{
			std::cout << x << " ";
		}
		std::cout << "\n";
	}
}


int main()
{
	std::vector<int> adj[4];

	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 3);

	printAdj(adj, sizeof(adj) / sizeof(adj[0]));

	return 0;
}