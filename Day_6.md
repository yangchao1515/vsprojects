题目ID：不要2
链接：https://www.nowcoder.com/practice/1183548cd48446b38da501e58d5944eb?tpId=85&&tqId=29840&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

```c++
#include<iostream> 
#include<vector>
using namespace std;
int main() 
{    
	int w,h,res = 0;    
	cin >> w >> h;   
	vector<vector<int>> a;    
	a.resize(w);   
	for(auto& e : a)       
		e.resize(h, 1);       
	for(int i=0;i<w;i++)   
	{       
		for(int j=0;j<h;j++)    
		{           
			if(a[i][j]==1)  
			{                

				res++;   


		if((i+2)<w)                   
			a[i+2][j] = 0;       //不符合置零                  
		if((j+2)<h)                
			a[i][j+2] = 0;  

		}       
	}   
}   
cout << res;  

return 0; 


}
```

