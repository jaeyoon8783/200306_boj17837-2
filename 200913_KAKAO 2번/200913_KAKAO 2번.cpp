//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//#include <map>
//#include <set>
//#define pii pair<int, int>
//using namespace std;
//
//map<string, int> list[20];
//map<int, int> course_su;
//set<string> ss;
///*
//void input_list(int li, string str, int cur_pos, string cur_str)
//{
//	if (course_su[cur_str.size()] == 1)
//	{
//		list[li][cur_str] = 1;
//		ss.insert(cur_str);
//	}
//
//	if (cur_pos == str.size())
//		return;
//
//	input_list(li,str, cur_pos + 1, cur_str + str[cur_pos]);
//	input_list(li,str, cur_pos + 1, cur_str);
//
//
//}
//int testing(string candi, string str) // 1이면 품기 가능, 0이면 아무런 관련 없다. 2면 품어져버림
//{
//	
//	map<char, int> c_map;
//	for (int i = 0; i < candi.size(); i++)
//		c_map[candi[i]] = 1;
//
//	int cnt = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (c_map[str[i]] == 1)
//			cnt++;
//	}
//	
//	if (cnt == str.size() && cnt < candi.size()) // str이 먹힘
//		return 1;
//	else if (cnt == candi.size() && cnt < str.size())
//		return 2;
//	else
//		return 0;
//	
//	
//	// 1이면 candi가 ans[i] 품을 수 있다.
//	// 2이면 ans[i]가 candi 품기 가능
//
//}
//
//
//vector<string> solution(vector<string> orders, vector<int> course) {
//	
//	for (int i = 0; i < course.size(); i++)
//		course_su[course[i]] = 1;
//
//	for (int i = 0; i < orders.size(); i++)
//	{
//		input_list(i,orders[i],0, "");
//	}
//	
//	/*
//	for (int i = 0; i < orders.size(); i++)
//	{
//		auto itr = list[i].begin();
//
//		while (itr != list[i].end())
//		{
//			cout << (*itr).first << ' ';
//			itr++;
//		}
//		cout << '\n';
//
//	}
//	*/
//	vector<string> ans;
//
//	auto itr = ss.begin();
//	while (itr != ss.end())
//	{
//		string candi = (*itr);
//		
//		int cnt = 0;
//		for (int i = 0; i < orders.size(); i++)
//		{
//			if (list[i][candi] == 1)
//				cnt++;
//		}
//		
//		if (cnt >= 2)
//		{
//			cout << candi << ' ' << cnt << '\n';
//			int i;
//			/*
//			for (i = 0; i < ans.size(); i++) 
//			{
//				int flag = testing(candi, ans[i]); 
//				if (flag == 0) // 0이면 관련 X
//					continue;
//				if (flag == 1) // 1이면 candi가 ans[i] 품을 수 있다.
//				{
//					ans[i] = candi;
//					break;
//				}
//				else       // 2이면 ans[i]가 candi 품기 가능
//					break;
//			}
//			if(i == ans.size())
//			*/
//				ans.push_back(candi);
//		}
//		itr++;
//	}
//
//	return ans;
//	
//}
//
//
//
//int main()
//{
//	vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
//	vector<int> course = { 2,3,4 };
//	//vector<string> orders = { "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" };
//	//vector<int> course = { 2,3,5 };
//
//	vector<string> aan = solution(orders, course);
//
//	for (int i = 0; i < aan.size(); i++)
//	{
//		cout << aan[i] << ' ';
//	}
//
//	
//
//
//
//}
