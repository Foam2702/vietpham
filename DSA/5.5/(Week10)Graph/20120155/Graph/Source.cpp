#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#define MAX 100
using namespace std;
struct Graph
{
	int num_vertices;
	vector<vector<int>>adjacency_matrix;
};
Graph Read_File(string filename)
{
	Graph G;
	fstream f;
	f.open(filename);
	if (!f.is_open()) {
		cout << "ERROR\n";
	}
	else
	{
		int n;
		f >> n;
		G.num_vertices = n;
		for (int i = 0; i < n; i++)
		{
			vector<int>a;
			for (int j = 0; j < n; j++)
			{
				int x;
				f >> x;
				a.push_back(x);
			}
			G.adjacency_matrix.push_back(a);
		}
	}
	f.close();
	return G;
}
void Display(Graph G) {
	for (int i = 0; i < G.num_vertices; i++)
	{
		cout << i << " : ";
		for (int j = 0; j < G.num_vertices; j++)
		{
			if (G.adjacency_matrix[i][j] > 0)
			{
				cout << j << " ";
			}
		}
		cout << endl;
	}
}
bool UndirectedGraph(Graph G) {
	for (int i = 0; i < G.num_vertices; i++)
	{
		for (int j = 0; j < G.num_vertices; j++)
		{
			if (G.adjacency_matrix[i][j] != G.adjacency_matrix[j][i])
			{
				return false;
			}
		}
	}
	return true;
}
int Count_Edges(Graph G)
{
	int count = 0;
	if (UndirectedGraph(G) == true)
	{
		for (int i = 0; i < G.num_vertices; i++)
		{
			for (int j = i; j < G.num_vertices; j++)
			{
				count += G.adjacency_matrix[i][j];
			}
		}
	}
	else if (UndirectedGraph(G) == false)
	{
		for (int i = 0; i < G.num_vertices; i++)
		{
			for (int j = 0; j < G.num_vertices; j++)
			{
				count += G.adjacency_matrix[i][j];
			}
		}
	}
	return count;
}
void List_DegreeOfVertices(Graph G)
{
	if (UndirectedGraph(G))
	{
		for (int i = 0; i < G.num_vertices; i++)
		{
			int count = 0;
			for (int j = 0; j < G.num_vertices; j++)
			{
				count += G.adjacency_matrix[i][j];
			}
			cout << "So bac dinh " << i << ": " << count << endl;
		}
	}
	else if (UndirectedGraph(G) == false)
	{
		for (int i = 0; i < G.num_vertices; i++)
		{
			int count_out = 0;
			for (int j = 0; j < G.num_vertices; j++)
			{
				count_out += G.adjacency_matrix[i][j];

			}
			cout << "So bac ra dinh " << i << ": " << count_out << endl;
			int count_in = 0;
			for (int j = 0; j < G.num_vertices; j++)
			{
				count_in += G.adjacency_matrix[j][i];
			}
			cout << "So bac vao dinh " << i << ": " << count_in << endl;
		}

	}
}
void DFS(Graph G, int start,bool check[] )
{
	check[start] = false;

	for (int i = 0; i < G.num_vertices; i++)
	{
		if (G.adjacency_matrix[start][i] == 1 && check[i])
		{
			DFS(G, i, check);
		}
	}
}
void BFS(Graph G, int start, bool check[])
{
	queue<int>list;
	for (int i = 0; i < G.num_vertices; i++)
	{
		check[i] = false;
	}
	check[start] = true;
	list.push(start);
	while (!list.empty())
	{
		start = list.front();
		list.pop();
		cout << start << " ";
		for (int i = 0; i < G.num_vertices; i++)
		{
			if (!check[i])
			{
				check[i] = 1;
				list.push(i);
			}
		}
	}
}
bool ConnectedGraph(Graph G, bool check[])
{
	for (int i = 0; i < G.num_vertices; i++)
	{
		check[i] = 0;
	}
	for (int i = 0; i < G.num_vertices; i++)
	{
		if (!check[i])
		{
			return true;
			DFS(G, i, check);
		}
	}
	return false;
}
int Count_ConnectedGraph(Graph G, bool check[])
{
	int count = 0;
	for (int i = 0; i < G.num_vertices; i++)
	{
		if (!check[i])
		{
			count++;
			DFS(G, i, check);
		}
	}
	return count;
}

int main()
{
	Graph G;
	G = Read_File("graph.txt");
	Display(G);
	if (UndirectedGraph(G))
	{
		cout << "Do thi vo huong!" << endl;
	}
	else
	{
		cout << "Do thi co huong!" << endl;
	}
	cout << "So canh cua do thi: " << Count_Edges(G) << endl;
	List_DegreeOfVertices(G);
	bool check_DFS[MAX];
	cout << " DFS: " << endl;
	DFS(G, 2, check_DFS);
	bool check_BFS[MAX];
	cout << " BFS: " << endl;
	BFS(G, 2, check_BFS);
	bool check_Connected[MAX];
	if (ConnectedGraph(G, check_Connected) == true)
	{
		cout << "Do thi co lien thong!" << endl;
	}
	else {
		cout << "Do thi khong lien thong!" << endl;
	}
	bool check_Connected1[MAX];
	cout << "So thanh phan lien thong: " << Count_ConnectedGraph(G, check_Connected1);
	system("pause");
}
