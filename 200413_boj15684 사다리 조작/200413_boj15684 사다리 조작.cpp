#include <iostream>
#include <algorithm>
using namespace std;

int n, m, h; // 세로선, 선분개수 , 가로선
int arr[31][11] = { 0 }; // 가로선 , 세로선
int ans = 987654321;

void make(int cnt)
{
	
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
	
	for (int i = 1; i < n; i++)
	{
		int temp = i;
		for (int j = 1; j <= h; j++)
		{
			if (arr[j][temp] == 1)
				temp = temp + 1;
			else if (arr[j][temp - 1] == 1)
				temp = temp - 1;
		}

		if (temp != i)
			return;
	}


	if (ans > cnt)
		ans = cnt;
}

void go(int cnt, int ti)
{
	if (cnt > 3)
		return;
	else
		make(cnt);

	for (int i = ti; i <= h; i++) // h == 가
	{
		for (int j = 1; j <= n - 1; j++)  // n == 세
		{
			if (arr[i][j] == 0 && arr[i][j - 1] == 0 && arr[i][j + 1] == 0)
			{
				arr[i][j] = 1;
				go(cnt + 1, i); //시벌 이게 문제네
				arr[i][j] = 0;
			}
		}
	}
	
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> n >> m >> h; //n 세   h가

	int x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		arr[x][y] = 1;
	}


	go(0, 1);


	if (ans == 987654321)
		cout << -1;
	else
		cout << ans;


}