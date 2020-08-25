#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

int solution(vector<int> people, int limit)
{
	sort(people.begin(), people.end(), greater<int>());

	int ans = 0;
	int start = 0;
	int end = people.size()-1;

	while (1)
	{
		if (start > end)
			break;
		if (start == end)
		{
			ans++; break;
		}

		if (people[start] + people[end] > limit)
		{
			start++; ans++;
		}
		else
		{
			start++; end--; ans++;
		}
	}
	

	return ans;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> p = { 70,50,80,50 };
	int limit = 100;

	cout << solution(p, limit);
}
