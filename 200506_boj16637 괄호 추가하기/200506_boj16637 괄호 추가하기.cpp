#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define pii pair<int, int>
using namespace std;

int n; // 부호 개수 = n/2
char arr[19];
int ans = INT_MIN;
int su[10];
char bu[9];
int first[9];

void go(int cnt)
{
	if (cnt >= n/2)
	{
		/*
		for (int i = 0; i < n/2; i++)
			cout << first[i] << ' ';
		cout << "\n";
		*/
		int check_su[10] = { 0 };
		
		int temp_su[10];
		copy(su , su+(n/2+1), temp_su);


		for (int i = 0; i < n / 2; i++)
		{
			if (first[i] == 1)
			{
				if (bu[i] == '+')
					temp_su[i + 1] = temp_su[i] + temp_su[i + 1];
				else if (bu[i] == '-')
					temp_su[i + 1] = temp_su[i] - temp_su[i + 1];
				else if (bu[i] == '*')
					temp_su[i + 1] = temp_su[i] * temp_su[i + 1];

				check_su[i] = 1;
			}
		}
		
		int flag = 0;
		int can;
		char t;

		for (int i = 0; i <= n / 2; i++)
		{
			if (check_su[i] == 1)
				continue;
			if (flag == 0)
			{
				can = temp_su[i];
				t = bu[i];
				flag = 1;
			}
			else
			{
				if (t == '+')
					can += temp_su[i];
				else if (t == '-')
					can -= temp_su[i];
				else if (t == '*')
					can *= temp_su[i];

				if (i != n / 2)
					t = bu[i];
			}

		}
		//cout << can << "\n";
		ans = max(ans, can);

		
	
		
		return;
	}
	if (cnt == 0 || first[cnt - 1] == 0)
	{
		first[cnt] = 1;
		go(cnt + 1);
		first[cnt] = 0;
	}
	go(cnt + 1);

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			su[i / 2] = arr[i] - '0';
		else
			bu[(i - 1) / 2] = arr[i];
	}
	// n이 9면 수 개수는 5, 부호 개수는 4.
	/*
	for (int i = 0; i <= n / 2; i++)
		cout << su[i] << ' ';
	for (int i = 0; i < n / 2; i++)
		cout << bu[i] << ' ';
	cout << '\n';
	*/

	go(0);
	cout << ans;
}
