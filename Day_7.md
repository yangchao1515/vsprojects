题目ID：45846 --Fibonacci数列 

链接：https://www.nowcoder.com/practice/18ecd0ecf5ef4fe9ba3f17f8d00d2d66?tpId=85&&tqId=29846&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking



```c++
#include <iostream>
using namespace std;
int main()
{
	int N, f, l = 0, r = 0, f0 = 0, f1 = 1;
	cin >> N;
	while (1)
	{
		f = f0 + f1;
		f0 = f1;
		f1 = f;        //找到比N小且距离N最近的数，求出距离

		if (f < N)
			l = N - f;
		else
		{            //找到比N大且距离N最近的数，求出距离          

			r = f - N;
			break;
		}
	} //取最小距离   
	cout << min(l, r) << endl;
	return 0;
}
```





题目ID：36939-合法括号序列判断 

链接：https://www.nowcoder.com/practice/d8acfa0619814b2d98f12c071aef20d4?tpId=8&&tqId=11039&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking



```C++
class Parenthesis {
public:   
	bool chkParenthesis(string A, int n) 
	{    
		stack<char> sc;      
		for (auto ele : A) 
		{           
			switch (ele) 
			{               
			case '(':                   
				sc.push(ele);                   
				break;               
			case ')':                    
			{                       
						if (sc.empty() || sc.top() != '(')                          
							return false;                       
						else                           
							sc.pop();                  
			}                  
				break;          
			default:            
				return false;           
			}     
		}       
		return true;   
	} 
};
```

