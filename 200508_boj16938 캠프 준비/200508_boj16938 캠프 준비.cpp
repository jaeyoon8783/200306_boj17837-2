#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
using namespace std;

int n, l, r, x;
int arr[15];
int can[15] = { 0 };
int ans = 0;

void go(int hap, int arr_cnt, int can_cnt)
{
	
	if (arr_cnt >= n)
	{

		if (can_cnt >= 2 && hap >= l && hap <= r && can[can_cnt - 1] - can[0] >= x)
		{/*
			for (int i = 0; i < can_cnt; i++)
				cout << can[i] << ' ';
			cout << hap << "\n";
			*/
			ans++;
		}
		return;
	}

	can[can_cnt] = arr[arr_cnt];
	go(hap + arr[arr_cnt], arr_cnt + 1, can_cnt+ 1);
	can[can_cnt] = 0;
	go(hap, arr_cnt + 1, can_cnt);

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	

	cin >> n >> l >> r >> x;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	go(0,0,0);
	cout << ans;
}
