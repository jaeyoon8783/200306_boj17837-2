#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;
bool comp(const pii& a, const pii& b)
{
	if (a.first != b.first)
		return a.second < b.second;
	else
		return a.first < b.first;

	
}

string make(int time)
{
	string h = to_string(time / 3600);
	if (h.size() == 1)
		h = '0' + h;
	string m = to_string((time % 3600)/60);
	if (m.size() == 1)
		m = '0' + m;
	string s = to_string(time % 60);
	if (s.size() == 1)
		s = '0' + s;


	return h+':'+m+':'+s;
}


string solution(string play_time, string adv_time, vector<string> logs)
{
	int p_time = 0;

	int h = stoi(play_time.substr(0, 2));
	int m = stoi(play_time.substr(3, 2));
	int s = stoi(play_time.substr(6, 2));
	p_time = s + m * 60 + h * 3600;

	int a_time = 0;
	 h = stoi(adv_time.substr(0, 2));
	 m = stoi(adv_time.substr(3, 2));
	 s = stoi(adv_time.substr(6, 2));
	a_time = s + m * 60 + h * 3600;

	vector<pii> condi;

	for (int i = 0; i < logs.size(); i++)
	{
		int log_start = 0;
		
		h = stoi(logs[i].substr(0, 2));
		m = stoi(logs[i].substr(3, 2));
		s = stoi(logs[i].substr(6, 2));
		log_start = s + m * 60 + h * 3600;

		int log_end = 0;
		h = stoi(logs[i].substr(9, 2));
		m = stoi(logs[i].substr(12, 2));
		s = stoi(logs[i].substr(15, 2));
		log_end = s + m * 60 + h * 3600;
		condi.push_back({ log_start, log_end });

	}

	sort(condi.begin(), condi.end(), comp);
	/*
	for (int i = 0; i < condi.size(); i++)
	{
		cout << condi[i].first << ' ' << condi[i].second << '\n';
	}
	*/
	int ans_time = 0;
	int ans_nu = 0;

	int tmp_start = 0;
	int tmp_end = tmp_start + a_time;
	int nu = 0;
	for (int j = 0; j < condi.size(); j++)
	{
		
		if (condi[j].first >= tmp_end)
			break;

		int nu_start = max(tmp_start, condi[j].first);
		int nu_end = min(tmp_end, condi[j].second);
		nu += (nu_end - nu_start);
	}
	if (nu > ans_nu)
	{
		ans_time = tmp_start;
		ans_nu = nu;
	}

	for (int i = 0; i < condi.size(); i++)
	{
		tmp_start = condi[i].first;
		tmp_end = tmp_start + a_time;//
	//	cout << tmp_start << ' ' << tmp_end << ' ';
		nu = 0;
		int flag = 0;
		if (tmp_end > p_time)
		{
			tmp_start -= (tmp_end - p_time);
			tmp_end = p_time;
			
			flag = 1;
		}
		for (int j = i; j < condi.size(); j++)
		{
			if (condi[j].first >= tmp_end)
				break;
			int nu_start = max(tmp_start, condi[j].first);
			int nu_end = min(tmp_end, condi[j].second);
			nu += (nu_end - nu_start);
		}
	//	cout << nu << '\n';
		if (nu > ans_nu)
		{
			ans_time = tmp_start;
			ans_nu = nu;
		}

		if (flag == 1)
			break;
	}

	string aaa = make(ans_time);


	return aaa;

}

int main()
{
	string play_time = "02:03:55";
	string adv_time = "00:14:15";
	vector<string> logs = { "01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30" };

	cout << solution(play_time, adv_time, logs);
}
