#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

vector<vector<int>> ans;
void go(int from, int to, int remain ,int n) // 1->3 , 2
{
	if (n == 0)
		return;

	go(from, remain, to, n - 1); // 1->2 , 3
	ans.push_back({ from, to });
	//cout << from << ' ' << to << ' ' << n << '\n';
	go(remain, to, from, n-1);     // 2->3 , 1

}



vector<vector<int>> solution(int n)
{
	

	go(1, 3, 2, n);

	return ans;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 3;
	vector<vector<int>> s  = solution(n);

	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i][0] << ' ' << s[i][1] << '\n';
	}


}
