//2139
#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
using namespace std;

int n;
int map[16][16];
int check[16][16][3] = { 0 }; // i,j를 가로로 설치 = 0 , 세로로설치 =1 , 대각으로 설치 = 2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	for (int i = 1; i < n; i++)
	{
		if (map[0][i] == 0)
			check[0][i][0] = 1;
		else
			break;
	}
		

	for (int i = 1; i < n; i++)
	{
		for (int j = 2; j < n; j++)
		{
			if (map[i][j] == 0)
			{
				check[i][j][0] = check[i][j - 1][0] + check[i][j - 1][2];
				check[i][j][1] = check[i - 1][j][1] + check[i - 1][j][2];
				
				if (map[i - 1][j] == 0 && map[i][j - 1] == 0)
				{
					check[i][j][2] = check[i - 1][j - 1][0] + check[i - 1][j - 1][2] + check[i - 1][j - 1][1]; // 세
				}
				
			}
			
			
		}
	}

	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << check[i][j][0] << check[i][j][1] << check[i][j][2] << ' ';
		}
		cout << "\n";
	}


	//cout << check[n - 1][n - 1][0] + check[n - 1][n - 1][1] + check[n - 1][n - 1][2];

}


/*
6
0 0 0 1 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 1 0 0
0 0 0 0 0 0
0 0 0 0 0 0


*/