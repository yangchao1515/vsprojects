题目ID：45844 --两种排序方法 

链接：<https://www.nowcoder.com/practice/839f681bf36c486fbcc5fcb977ffe432?tpId=85&&tqId=29844&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking>



```
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	 int n; 
    cin>>n; 
    vector<string> v;
    v.resize(n); 
    for(auto& str : v)    
        cin>>str;
 bool lensym = true, lexsym = true;
	for (size_t i = 1; i<v.size(); ++i)
	{
		if (v[i - 1] >= v[i])
		{
			lexsym = false;		//字母大小不符合
			break;
		}
	}
	//length
	for (size_t i = 1; i<v.size(); ++i)
	{
		if (v[i - 1].size() >= v[i].size())
		{
			lensym = false;	//长度不符合
			break;
		}
	}

	if (lensym && lexsym )
	{
		printf("both");
	}

	

	else if (lensym  && !lexsym )
	{
		printf("lengths");
	}
    
    else if (!lensym && lexsym)
	{
		printf("lexicographically");
	}

	else if (!lensym  && !lexsym )
	{
		printf("none");
	}

	cout << endl;
	system("pause");
	return 0;
}

```







题目ID：36932-求最小公倍数 

链接：https://www.nowcoder.com/practice/22948c2cad484e0291350abad86136c3?tpId=37&&tqId=21331&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking



```
#define _CRT_SECURE_NO_WARNINGS 1
#include
#include
#include
using namespace std;
int main()
{
int m, n;
cin >> m >> n;
if (m < n)
{
swap(m, n);
}
if (m%n == 0)
{
printf("%d\n", m);
}
int i;
for (i = m; 1; i++)
{
if (i%m == 0 && i%n == 0)
{
break;
}
}
cout << i << endl;
system("pause");
return 0;
}
```

