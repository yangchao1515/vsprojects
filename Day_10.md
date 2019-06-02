题目ID：24992 --井字棋 
链接：https://www.nowcoder.com/practice/e1bb714eb9924188a0d5a6df2216a3d1?tpId=8&&tqId=11055&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking



```c++
class Board {
public:
	bool checkWon(vector<vector<int>> board) 
	{
		
		int sum = 0;
		int row = board.size();
		int i = 0, j = 0;

		//检测行是否相等

		for (i = 0; i < row; i++)
		{
			sum = 0;
			for (j = 0; j < row; j++)
			{
				sum += board[i][j];
			}

			if (sum == row)		//满足
			{
				return true;
			}
		}

			//检测列是否相等

			sum = 0;

			for (i = 0; i < row; i++)
			{
				sum = 0;
				for (j = 0; j < row; j++)
				{
					sum += board[j][i];
				}

				if (sum == row)		//满足
				{
					return true;
				}

			}


				//检测主对角线是否相等

				sum = 0;


				for (i = 0; i < row; i++)
				{

					sum += board[i][i];
					
				}
				if (sum == row)		//满足
				{
					return true;
				}

				sum = 0;


				//检测副对角线是否相等

				sum = 0;


				for (i = 0; i < row; i++)
				{

					sum += board[i][row-1-i];
					
				}
				if (sum == row)		//满足
				{
					return true;
				}
        return false;
		
	
	}
};
```



【题目ID】：36911-密码强度等级 
链接：https://www.nowcoder.com/practice/52d382c2a7164767bca2064c1c9d5361?tpId=37&&tqId=21310&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

```c++
#include<iostream>
#include<string>
using namespace std;
int num_char(string str,int k)
    {
    int small=0;
    int big=0;
    for(int i=0;i<k;i++)
        {
        if(str[i]>=65&&str[i]<=90)
            big++;
        else if(str[i]>=97&&str[i]<=122)
            small++;
    }
    if((small+big)==0)
        return 0;
    else if(small==k||big==k)
        return 10;
    else if(small>0&&big>0)
        return 20;
    return 0;
}
int num_number(string str,int k)
    {
    int num=0;
    for(int i=0;i<k;i++)
        {
        if(str[i]-'0'>=0&&str[i]-'0'<=9)
            num++;
    }
    if(num==0)
        return 0;
    else if(num==1)
        return 10;
    else
        return 20;
}
int num_fuhao(string str,int k)
    {
    int num=0;
    for(int i=0;i<k;i++)
        {
        if(!(str[i]>=65&&str[i]<=90)&&!(str[i]>=97&&str[i]<=122)&&!(str[i]-'0'>=0&&str[i]-'0'<=9))
            num++;
    }
    if(num==0)
        return 0;
    else if(num==1)
        return 10;
    else
        return 25;   
}
int main()
{
    string str;
    while(cin>>str)
        {
        int sum1=0,sum2=0,sum3=0,sum4=0,sum5=0;
        int k=str.size();
        if(k<=4)
            sum1=5;
        else if(k>=8)
            sum1=25;
        else
            sum1=10;
        sum2=num_char(str,k);
        sum3=num_number(str,k);
        sum4=num_fuhao(str,k);
        if((sum2>0)&&(sum3>0)&&(sum4>0))
            {
            if(sum2==10)
                sum5=3;
            else
                sum5=5;
        }
        else if(sum2>0&&sum3>0&&sum4==0)
            sum5=2;
        if(sum1+sum2+sum3+sum4+sum5>=90)
            cout<<"VERY_SECURE"<<endl;
        else if(sum1+sum2+sum3+sum4+sum5>=80)
             cout<<"SECURE"<<endl;
        else if(sum1+sum2+sum3+sum4+sum5>=70)
            cout<<"VERY_STRONG"<<endl;
        else if(sum1+sum2+sum3+sum4+sum5>=60)
            cout<<"STRONG"<<endl;
        else if(sum1+sum2+sum3+sum4+sum5>=50)
            cout<<"AVERAGE"<<endl;
        else if(sum1+sum2+sum3+sum4+sum5>=25)
            cout<<"WEAK"<<endl;
        else
            cout<<"VERY_WEAK"<<endl;
    }
    return 0;
}
```

