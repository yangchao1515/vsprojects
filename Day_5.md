//题目ID：45842-统计回文 

[](https://www.cnblogs.com/liugang-vip/p/6337580.html)



```

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

```


