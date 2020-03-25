#include <iostream>
using namespace std;
int n, m, x, y, i, j, relations[100][100], color[100];
bool ability, used[100];

void DFS(int v, int col)
{
	int j;
	used[v] = false;
	color[v] = col;
	for (j = 0; j < n; j++)
		if (relations[v][j] != 0 && used[j])
			DFS(j, col*- 1);
}

int main()
{
	cin >> n >> m;
	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
			relations[i][j] = 0;
	for (i = 0; i < m; i++)
	{
		cin >> x >> y;
		relations[x][y] = 1;
		relations[y][x] = 1;
	}
	for (i = 0; i < n; i++)
		used[i] = true;
	for (i = 0; i < n; i++)
		color[i] = 0;
	for (i = 0; i < n; i++)
		if (used[i])
			DFS(i, 1);
	ability = true;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (color[i] == color[j] && relations[i][j] != 0)
				ability = false;
	if (ability)
	{
		cout << "YES" << endl;
		for (i = 0;i < n;i++)
			if (color[i] == 1)
			{
				cout << i;
				cout << ' ';
				cout << endl;
			}
	}
	else cout << "NO" << endl;
}
