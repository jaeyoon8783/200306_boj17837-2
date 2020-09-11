#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
#define ll long long 
using namespace std;

vector<int> solution(int n, ll k)
{
	int check[21] = { 0 };
	vector<int> ans;
	
	ll hap[21];
	hap[0] = 1;
	hap[1] = 1;

	for (int i = 2; i <= 20; i++)
	{
		hap[i] = i * hap[i - 1];
	}
	/*

	ll cur = 1;
	
	
	for (int i = n - 1; i >= 0; i--)
	{
		int j = 0;
		while (1)
		{
			j++;
			if (check[j] == 1)
				continue;
			cout << k << ' ' << (cur + hap[i]) << '\n';
			if (k >= cur + hap[i])
				cur += hap[i];
			else
			{
				ans.push_back(j);
				check[j] = 1;
				break;
			}

		}
	}


	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}

	*/
	return ans;

	
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);



	int n = 4;
	int k = 11;
	vector<int> ans = solution(n, k);

}
