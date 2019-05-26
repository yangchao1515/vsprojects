题目ID：45842-统计回文 

链接：https://www.cnblogs.com/liugang-vip/p/6337580.html



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





题目：连续最大和 
链接：https://www.nowcoder.com/practice/5a304c109a544aef9b583dce23f5f5db?tpId=85&&tqId=29858&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

	#include<iostream>
	#include<string>
	#include<vector>
	using namespace std;
		int main() 
		{
			int size;  
			cin >> size; 
			vector<int> nums(size); 
			for (size_t i = 0; i < size; ++i)  
				cin >> nums[i];       
			int result = nums[0];    
			int sum1 = 0, sum2 = 0;   
			for (int i = 0; i < nums.size(); i++)
			{
				//检测下一个加数是否为负数, 如果是负数，sum2就更新到下一个数继续检测 sum1来记录是否为负数
	
				sum2 = sum1 >= 0 ? sum1 + nums[i] : nums[i];      
																
				if (sum2 > result)		
				{
					result = sum2;
				}
	
				if (sum2 < 0)
				{
					sum2 = 0;
					
				}
				sum1 = sum2;
			}      
			cout << result << endl;   
			system("pause");
				return 0;
		}