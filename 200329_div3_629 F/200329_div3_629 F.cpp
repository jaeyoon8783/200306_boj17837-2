#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#define ll long long int
using namespace std;
int arr[200001];
map<int, int> ma;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m; // arr개수, 필요한 같은수

	int max_su_consist = 0;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		ma[arr[i]]++;
		max_su_consist = max(max_su_consist, ma[arr[i]]);
	}

	if (max_su_consist >= m) // 해야할꺼보다 이미 구성된게 더 많으면
	{
		cout << 0;
		return 0;
	}
	sort(arr, arr + n);

	ll num = 0;
	int u = 0;

	for (int i = 0; i < m; i++)
	{
		if (arr[i] == arr[m])
			u++;

		num += arr[m] - arr[i];
	}

	ans = min(ans,)



}
