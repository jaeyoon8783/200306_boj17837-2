#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;


bool comp(const int &a, const int &b)
{
	int t1 = stoi(to_string(a) + to_string(b));
	int t2 = stoi(to_string(b) + to_string(a));

	return t1 > t2;
}

string solution(vector<int> nums)
{
	string ans;
	sort(nums.begin(), nums.end(), comp);

	for (int i = 0; i < nums.size(); i++)
		ans += to_string(nums[i]);
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> nums = {0,0,0,0,1};

	cout << solution(nums);
}
