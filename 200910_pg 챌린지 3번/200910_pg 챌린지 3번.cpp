#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

int solution(vector<int> a)
{
	if (a.size() < 3)
		return a.size();


	int min_pos = 0;
	int su = 1000000001;

	for (int i = 0; i < a.size(); i++)
	{
		if (su > a[i])
		{
			su = a[i];
			min_pos = i;
		}
	}

	vector<int> aa(a.size(), 0); // 최솟값
	
	aa[min_pos] = a[min_pos];
	aa[0] = a[0];
	aa[a.size() - 1] = a[a.size() - 1];
	for (int i = 1; i <= min_pos - 1; i++)
	{
		if (a[i] < aa[i-1])
			aa[i] = a[i];
		else
			aa[i] = aa[i-1];
	}

	for (int i = a.size() - 2; i >= min_pos + 1; i--)
	{
		if (a[i] < aa[i+1])
			aa[i] = a[i];
		else
			aa[i] = aa[i+1];
	}

	int ans = 0;

	for (int i = 0; i < aa.size(); i++)
	{
	//	cout << aa[i] << ' ';
		if (a[i] == aa[i])
			ans++;
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	vector<int> arr= { -16,27,65,-2,58,-92,-71,-68,-61,-33 };
	cout << solution(arr);


}
