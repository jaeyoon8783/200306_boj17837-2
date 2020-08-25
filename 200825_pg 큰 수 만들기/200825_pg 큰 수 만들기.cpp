#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

string solution(string num, int k)
{
	int size = num.size();
	string ans = "";
	int pos = -1;
	for (int i = 0; i < (size-k); i++)
	{
		int max = -1;
		
		for (int j = pos+1; j <= k+i; j++)
		{
			if (max < num[j] - '0')
			{
				max = num[j] - '0';
				pos = j;
			}
		}
	
		ans += num[pos];
		//cout << ans << '\n';
	}

	return ans;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string number = "4177252841";
	int k = 4;

	cout << solution(number, k);
}
