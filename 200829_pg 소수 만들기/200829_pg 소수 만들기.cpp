#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;


int ans = 0;
int check[50] = { 0 };
int era[3001] = { 0 };
void go(vector<int> nums, int pos[],int cnt,int cur_pos)
{
	if (cnt == 3)
	{
		if (era[nums[pos[0]] + nums[pos[1]] + nums[pos[2]]] == 0)
		{
			ans++;
		}
		return;
	}

	if (cur_pos >= nums.size())
		return;

	pos[cnt] = cur_pos;
	go(nums, pos, cnt + 1, cur_pos + 1);
	go(nums, pos, cnt, cur_pos + 1);

}

int solution(vector<int> nums)
{
	era[0] = era[1] = 1;

	for (int i = 2; i <= 3000; i++)
	{
		if (era[i] == 1)
			continue;
	
		for (int j = i * 2; j <= 3000; j += i)
			era[j] = 1;
	
	}
	int pos[3];
	go(nums, pos, 0, 0);

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> num = { 1,2,7,6,4 };
	cout << solution(num);


}
