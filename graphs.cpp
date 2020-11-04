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

void bfs(std::vector<int> adj[], int u, bool arr[])
{
	std::queue<int> q;
	q.push(u);
	arr[u] = true;


	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		std::cout << cur << " ";

		for (auto a: adj[cur])
		{
			if (arr[a] == false)
			{
				q.push(a);
				arr[a] = true;
			}
		}
	}
}

int bfsDisconnect(std::vector<int> adj[], int v)
{
	int count = 0;
	bool *arr = new bool[v];

	for (int i = 0; i < v; i++)
		arr[i] = false;
	for (int i = 0; i < v; i++)
		if (arr[i] == false)
		{
			bfs(adj, i, arr);
			count++;
		}

	return count;
}

int main()
{
	std::vector<int> adj[5];

	//	0
	//	| \
	//	1--2
	//	| / |	
	//	3---4

	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 2, 3);
	addEdge(adj, 2, 4);
	addEdge(adj, 3, 4);

	std::cout << "Adjacency list representation of a graph : \n";
	printAdj(adj, 5);
	
	std::cout << "\nBreadth first traversal of a graph : ";
	int a = bfsDisconnect(adj, 5);
	std::cout << "\nNumber of islands : " << a;
	return 0;
}