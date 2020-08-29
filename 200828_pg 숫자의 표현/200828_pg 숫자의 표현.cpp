#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;


int solution(int n) 
{
	int ans = 0;
	int left = 1;
	int right = 1;
	int su = 1;

	while (right <= n)
	{
		if (su == n)
		{
			ans++;
			right++;
			su += right;
			su -= left;
			left++;
		}
		else if (su < n)
		{
			right++;
			su += right;
		}
		else
		{
			su -= left;
			left++;
		}
	}

	return ans;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 15;
	cout << solution(n);


}
