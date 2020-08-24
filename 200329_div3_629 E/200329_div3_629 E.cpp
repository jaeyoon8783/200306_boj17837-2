
#include <iostream>
#include <vector>
using namespace std;

vector<int> edge[200001];
int level[200001];
int parent_node[200001];
//int check[200001];
int check_cnt;


void dfs(int cur_node, int parent)
{

	level[cur_node] = level[parent] + 1;
	parent_node[cur_node] = parent;
	int size = edge[cur_node].size();
	for (int i = 0; i < size; i++)
	{
		int next = edge[cur_node][i];
		if (next == parent)
			continue;
		dfs(next, cur_node);
	}
}


void gogo(int check[], int cur_node, int parent)
{
	if (cur_node == 0)
	{
		if (check[1] == 1)
		{
			check_cnt++;
		}
		return;
	}
	int size = edge[cur_node].size();
	for (int i = 0; i < size; i++)
	{
		if (edge[cur_node][i] == parent)
			continue;
		if (check[edge[cur_node][i]] == 1)
		{
			check_cnt++;
		}
	}
	gogo(check, parent, parent_node[parent]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1, 0);

	for (int i = 0; i < m; i++)
	{
		int check[200001] = { 0 };
		check_cnt = 0;
		int x,y, max_level_node = 0;
		cin >> x;

		for (int j = 0; j < x; j++)
		{
			cin >> y;
			check[y] = 1;
			if (level[max_level_node] < level[y])
				max_level_node = y;
		}

		gogo(check, max_level_node, parent_node[max_level_node]);
	//	cout << check_cnt << " ";
		

		if (check_cnt == x)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}


	

}



/*
check에 대한 최적화를 어떻게 하면 좋을까에 대한 고민을 해보자


*/