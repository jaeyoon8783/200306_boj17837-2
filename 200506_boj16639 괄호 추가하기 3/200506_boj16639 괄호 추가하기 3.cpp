#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define pii pair<int, int>
using namespace std;

int n; // 부호 개수 = n/2개
char arr[19];
int ans = INT_MIN;
int su[10];
char bu[9];

int order[9];
int order_c[9] = { 0 };
void go(int cnt)
{
	if (cnt >= n / 2)
	{
		/*
		for (int i = 0; i < n/2; i++)
			cout << order[i] << ' ';
		cout << "\n";
		*/
		int check_su[10] = { 0 };
		int temp_su[10];
		copy(su, su + (n / 2 + 1), temp_su);


		for (int i = 0; i < n / 2; i++)
		{
			int bu_pos = order[i];
			char buho = bu[bu_pos];
			int first = temp_su[bu_pos];
			check_su[bu_pos] = 1;

			for (int j = bu_pos + 1; j <= n / 2; j++)
			{
				if (check_su[j] == 1)
					continue;
				else
				{
					if (buho == '+')
						temp_su[j] += first;
					else if (buho == '-')
						temp_su[j] = first-temp_su[j];
					else if (buho == '*')
						temp_su[j] *= first;

					if (i == n / 2 - 1)
					{
						ans = max(ans, temp_su[j]);
						//cout << temp_su[j] << "\n";
					}
					break;
				}
				
			}
		}

		return;
	}


	for (int i = 0; i < n/2; i++)
	{
		if (order_c[i] == 1)
			continue;
		order[cnt] = i;
		order_c[i] = 1;
		go(cnt + 1);
		order_c[i] = 0;
	}

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
	if (n == 1)
		cout << arr[0];
	else
	{
		go(0);
		cout << ans;
	}
	
}