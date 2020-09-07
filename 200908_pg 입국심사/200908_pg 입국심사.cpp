#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
#define ll long long
using namespace std;

ll solution(int n, vector<int> times)
{
	sort(times.begin(), times.end());
	ll low = 0;
	ll high = (ll)times[times.size() - 1] * (ll)n + 1;

	while (low < high)
	{
		ll mid = (low + high) / 2;
		ll cnt = 0;
		for (int i = 0; i < times.size(); i++)
			cnt += mid / times[i];
		
		if (cnt < n)
			low = mid + 1;
		else
			high = mid;

	}

	return high;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	int n = 6;
	vector<int> times = { 7,10 };

	cout << solution(n, times);

}
