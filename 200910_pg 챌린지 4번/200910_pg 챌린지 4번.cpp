#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

int solution(vector<vector<int>> a) {
	
	int cnt = 0;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[0].size(); j++)
		{
			cnt += a[i][j];
		}
	}
	if (cnt % 2 != 0)
		return 0;
	else
		return 0;

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);





}
