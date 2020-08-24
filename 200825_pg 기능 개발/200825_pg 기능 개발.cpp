#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {


	vector<int> answer;
	vector<int> time;

	for (int i = 0; i < progresses.size(); i++)
	{
		int remain = 100 - progresses[i];
		if (remain % speeds[i] == 0)
			time.push_back(remain / speeds[i]);
		else
			time.push_back(remain / speeds[i] + 1);

	}
	int max_time = time[0];
	int cnt = 1;
	for (int i = 1; i < time.size(); i++)
	{
		if (time[i] <= max_time)
		{
			cnt++;
		}
		else
		{
			max_time = time[i];
			answer.push_back(cnt);
			cnt = 1;

		}
	}
	answer.push_back(cnt);


	return answer;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> progresses = { 93,30,55 };
	vector<int> speeds = { 1,30,5 };

	vector<int> answer = solution(progresses, speeds);

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << ' ';

	
}
