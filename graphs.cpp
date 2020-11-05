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

void dfsRec(std::vector<int> adj[], int u, bool arr[])
{
	arr[u] = true;
	std::cout << u << " ";

	for (auto x : adj[u])
	{
		if (arr[x] == false)
		{
			arr[x] = true;
			dfsRec(adj, x, arr);
		}
	}
}

void dfs(std::vector<int> adj[], int v, int u)
{
	bool* arr = new bool[v];
	for (int i = 0; i < v; i++)
		arr[i] = false;

	// Add for loop and visited condition check to print disconnected graphs
	dfsRec(adj, u, arr);
	// Add count for counting components
}

void shortestUndirected(std::vector<int> adj[], int v, int u)
{
	bool* arr = new bool[v];
	for (int i = 0; i < v; i++)
		arr[i] = false;

	int* dist = new int[v];
	
	std::queue<int> q;
	q.push(u);


	arr[u] = true;
	dist[u] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto x : adj[cur])
		{
			if (arr[x] == false)
			{
				dist[x] = dist[cur] + 1;
				arr[x] = true;
				q.push(x);
			}
		}
	}

	for (int i = 0; i < v; i++)
		std::cout << dist[i] << " ";
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
	//addEdge(adj, 2, 3);		Commenting to check dfs functionality
	addEdge(adj, 2, 4);
	addEdge(adj, 3, 4);

	std::cout << "Adjacency list representation of a graph : \n";
	printAdj(adj, 5);
	
	std::cout << "\nBreadth first traversal of a graph : ";
	int a = bfsDisconnect(adj, 5);
	std::cout << "\nNumber of islands : " << a;
	std::cout << "\nDepth first search : ";
	dfs(adj, 5, 0);

	std::cout << "\nShortest Path from a source : \n";
	shortestUndirected(adj, 5, 0);

	return 0;
}