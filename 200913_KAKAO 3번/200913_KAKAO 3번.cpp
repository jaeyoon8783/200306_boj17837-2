//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//#include <sstream>
//#include <map>
//#define pii pair<int, int>
//using namespace std;
//
//
//
//vector<string> split(string str, char delimiter) {
//	vector<string> internal;
//	stringstream ss(str);
//	string temp;
//
//	while (getline(ss, temp, delimiter)) {
//		internal.push_back(temp);
//	}
//
//	return internal;
//}
//
//map<string, int> column[5];
//void init()
//{
//	column[0]["cpp"] = 1;  column[0]["java"] = 2; column[0]["python"] = 3;
//	column[1]["backend"] = 1;  column[1]["frontend"] = 2;
//	column[2]["junior"] = 1; column[2]["senior"] = 2;
//	column[3]["chicken"] = 1; column[3]["pizza"] = 3;
//}
//
//vector<int> solution(vector<string> info, vector<string> query)
//{
//	vector<vector<string>> table(info.size(), vector<string>(5));
//	
//	//init();
//
//	for (int i = 0; i < info.size(); i++)
//	{
//		vector<string> line_vector = split(info[i], ' ');
//		table[i][0] = line_vector[0];
//		table[i][1] = line_vector[1];
//		table[i][2] = line_vector[2];
//		table[i][3] = line_vector[3];
//		table[i][4] = line_vector[4];
//
//	}
//
//	
//	for (int i = 0; i < info.size(); i++)
//	{
//		for (int j = 0; j < 5; j++)
//			cout << table[i][j] << ' ';
//		cout << '\n';
//	}
//	
//	vector<int> ans;
//	for (int i = 0; i < query.size(); i++)
//	{
//		vector<string> line_vector = split(query[i], ' ');
//		//0,2,4,6,7 이 각각
//		line_vector.erase(line_vector.begin() + 5);
//		line_vector.erase(line_vector.begin() + 3);
//		line_vector.erase(line_vector.begin() + 1);
//
//		int cnt = 0;
//		for (int j = 0; j < table.size(); j++)
//		{
//			for (int k = 0; k < 5; k++)
//			{
//				if (k == 4)
//				{
//					if (stoi(line_vector[k]) <= stoi(table[j][k]))
//						cnt++;
//					continue;
//				}
//				if (line_vector[k] == "-")
//					continue;
//				if (line_vector[k] != table[j][k])
//					break;
//			}
//			
//		}
//		ans.push_back(cnt);
//	
//	}
//
//
//
//	return ans;
//
//
//}
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
//	vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
//	
//	
//	vector<int> ans = solution(info, query);
//
//	for (int i = 0; i < ans.size(); i++)
//		cout << ans[i] << ' ';
//	
//
//}
//
//
//
//
///*
//int j = 0;
//string lan;
//while (info[i][j] != ' ')
//{
//	lan += info[i][j++];
//}
//table[i][0] = lan;
//j++;
//string what;
//while (info[i][j] != ' ')
//{
//	what += info[i][j++];
//}
//table[i][1] = what;
//j++;
//string year;
//while (info[i][j] != ' ')
//{
//	year += info[i][j++];
//}
//table[i][2] = year;
//j++;
//string food;
//while (info[i][j] != ' ')
//	food += info[i][j++];
//table[i][3] = food;
//j++;
//
//string score;
//while (j < info[i].size())
//	score += info[i][j++];
//table[i][4] = score;
//*/