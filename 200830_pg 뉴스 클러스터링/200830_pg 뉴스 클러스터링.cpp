#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

vector<string> arr1;
vector<string> arr2;
int kyo()
{
	int cnt = 0;
	int arr1_pos = 0;
	int arr2_pos = 0;

	while (arr1_pos < arr1.size() && arr2_pos < arr2.size())
	{
		if (arr1[arr1_pos] > arr2[arr2_pos])
			arr2_pos++;
		else if (arr1[arr1_pos] < arr2[arr2_pos])
			arr1_pos++;
		else
		{
			cnt++;
			arr1_pos++;
			arr2_pos++;
		}
	}

	return cnt;
}


int hap()
{
	
	int cnt = 0;
	int arr1_pos = 0;
	int arr2_pos = 0;

	while (arr1_pos < arr1.size() && arr2_pos < arr2.size())
	{
		if (arr1[arr1_pos] > arr2[arr2_pos])
		{
			arr2_pos++;
			cnt++;
		}
		else if (arr1[arr1_pos] < arr2[arr2_pos])
		{
			arr1_pos++;
			cnt++;
		}
		else
		{
			cnt++;
			arr1_pos++;
			arr2_pos++;
		}

	}

	if (arr1_pos < arr1.size())
		cnt += (arr1.size() - arr1_pos);
	else
		cnt += (arr2.size() - arr2_pos);

	return cnt;
	
}


int solution(string str1, string str2)
{
	

	for (int i = 0; i < str1.size() - 1; i++)
	{
		string tmp = str1.substr(i, 2);

		
		if (tmp[0] >= 'a' && tmp[0] <= 'z')
			tmp[0] = tmp[0] - 32;
		else if (tmp[0] < 'A' || tmp[0] > 'Z')
			continue;

		if (tmp[1] >= 'a' && tmp[1] <= 'z')
			tmp[1] = tmp[1] - 32;
		else if (tmp[1] < 'A' || tmp[0] > 'Z')
			continue;
		arr1.push_back(tmp);
	}

	for (int i = 0; i < str2.size() - 1; i++)
	{
		string tmp = str2.substr(i, 2);


		if (tmp[0] >= 'a' && tmp[0] <= 'z')
			tmp[0] = tmp[0] - 32;
		else if (tmp[0] < 'A' || tmp[0] > 'Z')
			continue;

		if (tmp[1] >= 'a' && tmp[1] <= 'z')
			tmp[1] = tmp[1] - 32;
		else if (tmp[1] < 'A' || tmp[0] > 'Z')
			continue;
		arr2.push_back(tmp);
	}

	if (arr1.size() == 0 && arr2.size() == 0)
		return 1;

	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	



	int aa = kyo();
	int bb = hap();
	 
	return (int)(((float)aa / bb) * 65536);

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str1 = "aa1+aa2";
	string str2 = "AAAA12";

	cout << solution(str1, str2);

}
