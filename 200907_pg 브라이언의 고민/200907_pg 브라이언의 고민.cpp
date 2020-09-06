#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define pii pair<int, int>
using namespace std;

bool is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return true;
	else
		return false;
}

bool is_upper(char c)
{
	if (c >= 'A'&& c <= 'Z')
		return true;
	else
		return false;
}


string solution(string str)
{
	string ans = "";
	map<char, int> m;
	int i;
	for (i = 0; i < str.size()-1; i++)
	{
		if (is_lower(str[i]) && is_lower(str[i + 1]))
		{
			return "invalid";
		}
		else if (is_lower(str[i]) && is_upper(str[i + 1])) // 소->대 == 규2
		{
			char tmp = str[i];
			if (m[tmp] != 0)
				return "invalid";
			else
				m[tmp] = 1;

			int j;
			string word = "";
			for (j = i + 1; j < str.size(); j++)
			{
				if (str[j] == tmp)
					break;
				word += str[j];
			}
			if (j == str.size())
				return "invalid";


			if (word.size() > 1 && is_lower(word[1])) // 규2 후 규 1
			{
				string nword = "";
				char tmp2 = word[1];
				if (m[tmp2] != 0)
					return "invalid";
				else
					m[tmp] = 1;

				for (int j = 0; j < word.size(); j++)
				{
					if (word[j] == tmp2)
						continue;
					nword += word[j];
				}

				for (int j = 0; j < nword.size(); j++)
				{
					if (is_lower(nword[j]))
						return "invalid";
				}


				word = nword;
			}
		
			//cout << word << ' ';
			ans += word + ' ';
			i = j;
		}
		else if (is_upper(str[i]) && is_lower(str[i + 1])) // 대->소 규 1
		{
			string word = "";
			char tmp = str[i + 1];
			if (m[tmp] != 0)
				return "invalid";
			else
				m[tmp] = 1;
			int j;
			for (j = i + 1; j < str.size(); j += 2)
			{
				if (str[j] == tmp)
					word += str[j-1];
				else
					break;
			}
			if (is_lower(str[j - 1]))
				return "invalid";
			word += str[j - 1];

			ans += word + ' ';
			i = j - 1;
		}
		else if (is_upper(str[i]) && is_upper(str[i + 1]))
		{
			ans += str[i];
			ans += ' ';
		}
	}

	if(i == str.size())
		return ans.substr(0, ans.size()-1);
	else
	{
		if (is_upper(str[i]))
		{
			ans += str[i];
			return ans;
		}
		else
			return "invalid";
	}


}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	string str = "Aa";

	cout << solution(str);

	//testcase.push_back("aA"); //invalid
//	testcase.push_back("HaEaLaLObWORLDb"); //HELL O WORLD prob


}


//int main() {
//	vector<string> testcase;
//	testcase.push_back("HaEaLaLaObWORLDb"); //HELLO WORLD
//	testcase.push_back("SpIpGpOpNpGJqOqA"); //SIGONG JOA
//	testcase.push_back("A"); //A 
//	testcase.push_back("HELLOWORLD"); //HELLOWORLD 
//	testcase.push_back("aHbEbLbLbOacWdOdRdLdDc"); //HELLO WORLD
//	testcase.push_back("HaEaLaLObWORLDb"); //HELL O WORLD prob
//	testcase.push_back("AAA"); //AAA 
//	testcase.push_back("aHELLOWORLDa"); //HELLOWORLD 
//	testcase.push_back("AAAaBaAbBBBBbCcBdBdBdBcCeBfBeGgGGjGjGRvRvRvRvRvR"); //AA ABA BBBB C BBBB C BB GG GGG 
//	testcase.push_back("aIaAM"); //I AM
//	testcase.push_back("bAaOb"); //AO 
//	testcase.push_back("AxAxAxAoBoBoB"); //invalid 
//	testcase.push_back("a"); //invalid
//	testcase.push_back("Aa"); //invalid 
//	testcase.push_back("aA"); //invalid 
//	testcase.push_back("HaEaLaLaOWaOaRaLaD"); //invalid 
//	testcase.push_back("abHELLObaWORLD"); //invalid 
//	testcase.push_back("aHELLOa bWORLDb"); //invalid testcase.push_back("TxTxTxbAb"); //invalid 
//	testcase.push_back("bTxTxTaTxTbkABaCDk"); //invalid testcase.push_back("baHELLOabWORLD"); //invalid 
//	testcase.push_back("AxAxAxABcBcBcB"); //AAAA BBBB testcase.push_back("A B"); //invalid 
//	testcase.push_back("oBBoA"); //BB A testcase.push_back("AxAxAxA"); //AAAA 
//	testcase.push_back("HaEaLaLaObWORLDbSpIpGpOpNpGJqOqAdGcWcFcDdeGfWfLeoBBoAAAAxAxAxAA"); //HELLO WORLD SIGONG J O A GWFD GWL BB AAA AAAA A 
//	testcase.push_back("aBcAadDeEdvAvlElmEEEEm"); //BA DE A E EEEE 
//	testcase.push_back("AcAcABaBaB"); //A A AB B B 
//	testcase.push_back("aGbWbFbDakGnWnLk"); //GWFD GWL 
//	testcase.push_back("aCaCa"); //invalid 
//	for (int i = 0; i < testcase.size(); ++i)
//	{
//		cout << '[' << solution(testcase[i]) << ']' << '\n';
//	} return 0;
//}
