#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
#define ll long long
using namespace std;


ll arr[100];
vector<int> bu[3];
int su = 0;

ll calcul(ll a, ll b, int bu)
{
	if (bu == 0)
		return a + b;
	else if (bu == 1)
		return a - b;
	else
		return a * b;
}

ll go(int arr2[])
{

	int check[100] = { 0 };
	ll tmp_arr[100];
	copy(arr, arr + su, tmp_arr);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < bu[arr2[i]].size(); j++)
		{
			int pos = bu[arr2[i]][j];
			check[pos] = 1;

			ll tmp1 = tmp_arr[pos]; // 오
			ll tmp2;           // 왼

			while (pos >= 0)
			{
				if (check[pos] == 1)
					pos--;
				else
					break;
			}
			tmp_arr[pos] = calcul(tmp_arr[pos], tmp1, arr2[i]);
		}
	}

	return abs(tmp_arr[0]);
}

ll solution(string str)
{
	
	string tmp = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '+')
		{
			arr[su++] = stol(tmp);
			bu[0].push_back(su);
			tmp = "";
		}
		else if (str[i] == '-')
		{
			arr[su++] = stol(tmp);
			bu[1].push_back(su);
			tmp = "";
		}
		else if (str[i] == '*')
		{
			arr[su++] = stol(tmp);
			bu[2].push_back(su);
			tmp = "";
		}
		else
			tmp += str[i];
	}
	arr[su++] = stol(tmp);

	ll ans = -1;
	
	/*for (int i = 0; i < su; i++)
	{
		cout << arr[i] << ' ';
	}*/

	int dsa[6][3] = { {0,1,2},{0,2,1},{1,0,2}, {1,2,0}, {2,0,1}, {2,1,0} };

	for (int i = 0; i < 6; i++)
	{
		//cout << go(dsa[i]) << "\n";
		ans = max(ans, go(dsa[i]));
	}
	return ans;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str = "100-200*300-500+20";

	cout << solution(str);



}
