//题目ID：45842-统计回文 
//链接：https://www.nowcoder.com/practice/9d1559511b3849deaa71b576fa7009dc?tpId=85&&tqId=29 842&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

#include<iostream>
#include<string>

using namespace std;

int Is_Huiwen(string s)
{
	int start = 0;
	int end = s.size() - 1;
	while (start < end)
	{
		if (s[start] != s[end])
		{
			return 0;
		}
		start++;;
		end--;
	}
	return 1;
}


int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;

	int count = 0;
	int ret = 0;
	int length = s1.size()+1;

	string s3;
	string s4;
	while (length--)
	{
		s3 = s1;
		s4 = s3.insert(ret, s2);

		if ((Is_Huiwen(s3) == 1))
		{
			count++;
		}

		ret++;
		
	}

	cout << count << endl;
	system("pause");
	return 0;
}