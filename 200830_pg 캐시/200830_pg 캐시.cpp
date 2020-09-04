#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define pii pair<int, int>
using namespace std;

string convert(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = (str[i] + 32);
	}
	return str;
}

int solution(int cache, vector<string> cities)
{
	int ans = 0;
	vector<string> que;

	for (int i = 0; i < cities.size() ; i++)
	{
		string str = convert(cities[i]);
		int is_num = 5;
	
		for (int j = 0; j < que.size(); j++)
		{
			if (str == que[j])
			{
				is_num = 1;
				que.erase(que.begin() + j);
				break;
			}
		}

		que.push_back(str);
		if (que.size() > cache)
			que.erase(que.begin());

		ans += is_num;

		
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int csize = 5;
	vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"};
	cout << solution(csize, cities);
}
