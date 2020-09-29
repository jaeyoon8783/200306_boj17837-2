#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#define pii pair<int, int>
using namespace std;

map<char, int> list[20];
map<int, int> course_su;
map<string, int> aa;  // 알파벳과 사람 수

void input_list(int cur_pos, int cnt, int o_size, vector<int> person, int add)
{
	if (add == 1 && person.size() >= 2)
	{
		/*for (int i = 0; i < person.size(); i++)
			cout << person[i] << ' ';*/
		
		
		string str = "";
		for (char i = 'A'; i <= 'Z'; i++)
		{
			int j;
			for (j = 0; j < person.size(); j++)
			{
				if (list[person[j]][i] == 0)
					break;
			}
			if (j == person.size())
				str += i;
		}
		
		if (course_su[str.size()] == 1)
		{
		//	cout << str << ' ';
			aa[str] = person.size();
		}
		/*cout << '\n';*/
	}
	


	if (cur_pos == o_size)
		return;

	input_list(cur_pos + 1, cnt, o_size, person,0);
	person.push_back(cur_pos);
	input_list(cur_pos + 1, cnt + 1, o_size, person,1);


}


vector<string> solution(vector<string> orders, vector<int> course) {
	

	vector<int> person;
	for (int i = 0; i < orders.size(); i++)
	{
		for (int j = 0; j < orders[i].size(); j++)
			list[i][orders[i][j]] = 1;
	}
	for (int i = 0; i < course.size(); i++)
		course_su[course[i]] = 1;



	input_list(0, 0, orders.size(), person,0);
	
	vector<string> answer;
	
	int max_course[100] = { 0 }; // 코스 개수 에 대한 사람의 최대 수

	auto itr = aa.begin();

	while (itr != aa.end())
	{
		max_course[(*itr).first.size()] = max(max_course[(*itr).first.size()], (*itr).second);
		itr++;
	}

	
	itr = aa.begin();

	while (itr != aa.end())
	{
		if (max_course[(*itr).first.size()] == (*itr).second)
			answer.push_back((*itr).first);
		itr++;
	}
	sort(answer.begin(), answer.end());


	return answer;
	
}



int main()
{
	//vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
	//vector<int> course = { 2,3,4 };
	//vector<string> orders = { "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" };
//	vector<int> course = { 2,3,5 };
	vector<string> orders = { "ABC","ABC","DEF","DEF","DEF" };
	vector<int> course = { 3 };

	vector<string> aan = solution(orders, course);
	for (int i = 0; i < aan.size(); i++)
	{
		cout << aan[i] << ' ';
	}


}
