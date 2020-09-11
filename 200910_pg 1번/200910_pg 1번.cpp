#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define pii pair<int, int>
using namespace std;
vector<int> solution(vector<int> num) {


	set<int> s;
	for (int i = 0; i < num.size(); i++)
	{
		for (int j = i + 1; j < num.size(); j++)
		{
			s.insert(num[i] + num[j]);
		}
	}

	vector<int> ans;
	auto itr = s.begin();

	while (itr != s.end())
	{
		ans.push_back(*itr);
		itr++;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	


}
