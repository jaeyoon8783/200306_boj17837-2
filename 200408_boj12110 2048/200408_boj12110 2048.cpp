#include <iostream>
#include <algorithm>
using namespace std;
//21:57
int map[20][20];
int arr[5];
int n;
int check[20][20];
int ans = 0;
void go2()
{
	for (int z = 0; z < 5; z++)
	{
		int ok[20][20] = { 0 };
		int dir = arr[z];

		if (dir == 0) // 북
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					int k = j;
					if (check[j][i] == 0)
					{
						while (1)
						{
							k++;
							if (k >= n)
								break;
							if (check[k][i] != 0)
							{
								check[j][i] = check[k][i];
								check[k][i] = 0;
								break;
							}
						}

					}
					if (k >= n)
						break;
					if (j > 0 && (check[j][i] == check[j - 1][i]) && ok[j - 1][i] == 0)
					{
						check[j - 1][i] += check[j][i];
						check[j][i] = 0;
						ok[j - 1][i] = 1;
						j--;
					}
				}
			}
		}
		else if (dir == 3)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					int k = j;
					if (check[i][j] == 0)
					{
						while (1)
						{
							k++;
							if (k >= n)
								break;
							if (check[i][k] != 0)
							{
								check[i][j] = check[i][k];
								check[i][k] = 0;
								break;
							}
						}

					}
					if (k >= n)
						break;
					if (j > 0 && (check[i][j] == check[i][j - 1]) && ok[i][j-1] == 0)
					{
						check[i][j-1] += check[i][j];
						check[i][j] = 0;
						ok[i][j-1] = 1;
						j--;
					}
				}
			}
		}
		else if (dir == 1) // 남
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = n - 1; j >= 0; j--)
				{
					int k = j;
					if (check[j][i] == 0)
					{
						while (1)
						{
							k--;
							if (k < 0)
								break;
							if (check[k][i] != 0)
							{
								check[j][i] = check[k][i];
								check[k][i] = 0;
								break;
							}
						}
					}

					if (k < 0)
						break;
					if (j < n - 1 && (check[j][i] == check[j + 1][i]) && ok[j + 1][i] == 0)
					{
						check[j + 1][i] += check[j][i];
						check[j][i] = 0;
						ok[j + 1][i] = 1;
						j++;
					}
				}
			}
		}
		else if (dir == 2)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = n - 1; j >= 0; j--)
				{
					int k = j;
					if (check[i][j] == 0)
					{
						while (1)
						{
							k--;
							if (k < 0)
								break;
							if (check[i][k] != 0)
							{
								check[i][j] = check[i][k];
								check[i][k] = 0;
								break;
							}
						}
					}

					if (k < 0)
						break;
					if (j < n - 1 && (check[i][j] == check[i][j + 1]) && ok[i][j + 1] == 0)
					{
						check[i][j + 1] += check[i][j];
						check[i][j] = 0;
						ok[i][j + 1] = 1;
						j++;
					}

				}
			}
		}
	/*	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << check[i][j] << " ";
			cout << "\n";
		}*/
		
	}
	
		

		
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			ans = max(ans, check[i][j]);
	}

	
}



void go(int cur)
{
	
	/*arr[0] = arr[1] = arr[2] = arr[3] = arr[4] =3;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			check[i][j] = map[i][j];
	}
	go2();*/
	
	
	if (cur == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				check[i][j] = map[i][j];
		}
		go2();
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			arr[cur] = i;
			go(cur + 1);
		}

	}
	
}





int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	go(0);


	cout << ans;


}

/*
8
2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2


7
0 0 2 0 2 2 0
0 0 2 0 2 2 0
0 0 2 0 2 2 0
0 0 2 0 2 2 0
0 0 2 0 2 2 0
0 0 2 0 2 2 0
0 0 2 0 2 2 0

7
0 0 2 0 2 2 0
0 0 2 0 2 2 0
0 0 2 0 2 2 0
0 0 2 0 2 2 0
0 0 2 0 2 2 0
0 0 2 0 2 2 0
0 0 2 0 2 2 0

*/