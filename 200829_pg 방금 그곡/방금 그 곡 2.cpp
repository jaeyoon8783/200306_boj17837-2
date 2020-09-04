#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

string convert(string str) // #C 를 c 로, #A 를 a.. 등등 치환
{

	for (int i = 0; i < str.size()-1; i++)
	{
		if (str[i + 1] == '#')
		{
			string n;
			n += (str[i] + 32);
		//	cout << n << ' ';
			str.replace(i, 2, n);
		}
	}
	return str;

}


string solution(string m, vector<string> m_info)
{
	int ans_time = 0;
	string ans_str = "";
	m = convert(m);
	for (int i = 0; i < m_info.size(); i++)
	{
		string st_h, st_m;
		string en_h, en_m;
		int run_time;
		string title;
		string flow;
		int j = 0;

		while (m_info[i][j] != ':') st_h += m_info[i][j++];
		j++;
		while (m_info[i][j] != ',') st_m += m_info[i][j++];
		j++;
		while (m_info[i][j] != ':') en_h += m_info[i][j++];
		j++;
		while (m_info[i][j] != ',') en_m += m_info[i][j++];
		j++;
		while (m_info[i][j] != ',') title += m_info[i][j++];
		j++;
		while (j < m_info[i].size()) flow += m_info[i][j++];

		run_time = (stoi(en_h) - stoi(st_h)) * 60 + (stoi(en_m) - stoi(st_m));
		
		flow = convert(flow);

		//int m_length = m.size();


		int pos = 0;
		int flow_length = 0;
		string tmp = "";

		for (int j = 0; j < run_time; j++)
		{
			tmp += flow[pos];
			pos = (pos + 1) % flow.size();

			flow_length++;
			if (flow_length > m.size())
			{
				tmp.erase(0, 1);
				flow_length--;
			}

			if (tmp == m)
			{
				if (run_time > ans_time)
				{
					ans_time = run_time;
					ans_str = title;
				}
				break;
			}

		}

	}

	if (ans_str == "")
		return  "(None)";
	else
		return ans_str;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string m = "CC#BCC#BCC#BCC#B";
	vector<string> m_info = { "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" };

	cout << solution(m, m_info);
}
