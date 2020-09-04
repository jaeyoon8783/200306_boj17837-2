//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//#define pii pair<int, int>
//using namespace std;
//
//string solution(string m, vector<string> m_info)
//{
//	int ans_time = 0;
//	string ans_str = "";
//	for (int i = 0; i < m_info.size(); i++)
//	{
//		string st_h, st_m;
//		string en_h, en_m;
//		int run_time;
//		string title;
//		string flow;
//		int j = 0;
//
//
//		while (m_info[i][j] != ':') st_h += m_info[i][j++];
//		j++;
//		while (m_info[i][j] != ',') st_m += m_info[i][j++];
//		j++;
//		while (m_info[i][j] != ':') en_h += m_info[i][j++];
//		j++;
//		while (m_info[i][j] != ',') en_m += m_info[i][j++];
//		j++;
//		while (m_info[i][j] != ',') title += m_info[i][j++];
//		j++;
//		while (j < m_info[i].size()) flow += m_info[i][j++];
//
//		run_time = (stoi(en_h) - stoi(st_h)) * 60 + (stoi(en_m) - stoi(st_m));
//		//cout << run_time << ' ';
//
//		int m_length = 0;
//		for (int i = 0; i < m.size(); i++)
//		{
//			if (m[i] != '#')
//				m_length++;
//		}
//
//
//		int pos = 0;
//		int flow_length = 0;
//		string tmp = "";
//
//		for (int j = 0; j < run_time; j++)
//		{
//			if (flow[(pos+1)%flow.size()] == '#')
//			{
//				tmp += flow[pos];
//				pos = (pos + 1) % flow.size();
//				tmp += '#';
//				pos = (pos + 1) % flow.size();
//			}
//			else
//			{
//				tmp += flow[pos];
//				pos = (pos + 1) % flow.size();
//			}
//			flow_length++;
//
//			if (flow_length > m_length)
//			{
//				tmp.erase(0, 1);
//				if (tmp.size() != 0 && tmp[0] == '#')
//					tmp.erase(0, 1);
//				flow_length--;
//			}
//			
//
//			if (tmp == m)
//			{
//				if (run_time > ans_time)
//				{
//					ans_time = run_time;
//					ans_str = title;
//				}
//				break;
//			}
//				
//		}
//
//	}
//
//	if (ans_str == "")
//		return  "(None)";
//	else
//		return ans_str;
//}
//
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	string m = "ZABCDEFG";
//	vector<string> m_info = { "12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF" };
//
//	cout << solution(m, m_info);
//}
