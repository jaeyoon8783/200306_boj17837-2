#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

int solution(int n)
{
	int ans = 0;

	while (n > 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else
		{
			n -= 1;
			ans++;
		}
		//cout << n << ' ';
	}
	return ans + 1;
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 5000;
	cout << solution(n);

}
