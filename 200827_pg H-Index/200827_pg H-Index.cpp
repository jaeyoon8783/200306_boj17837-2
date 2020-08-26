#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;


int solution(vector<int> ci)
{
	sort(ci.begin(), ci.end());

	int ans;
	int pos = ci.size() - 1;
	for (ans = ci[ci.size() - 1]; ans >= 0; ans--)
	{
		while (1)
		{
			if (pos < 0 || ans > ci[pos])
			{
				pos++;
				break;
			}
			if (ans <= ci[pos])
				pos--;

		}

		if (ans <= ci.size() - pos && ans >= pos)
			return ans;
	}

	return ans;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> ci = { 20,21,22,23 };
	cout << solution(ci);

}

/*
{4,4,7,7,10,10};
{5,5,7,7,9,9,11,13};
9번에서 틀렸다.
*/
