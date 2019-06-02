题目ID：25083 --另类加法 

链接：https://www.nowcoder.com/practice/e7e0d226f1e84ba7ab8b28efc6e1aebc?tpId=8&&tqId=11065&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking



```c++
class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        int sum=0;
        int carry=0;
        while(B!=0)    //检测需不需要进位
        {
            sum=A^B; //得到没有进位的相加
           carry=(A&B)<<1;    //得到进位
            A=sum;    
            B=carry;
}
         return sum;
    }
   
};
```





题目ID：36915-求路径总数 
链接：https://www.nowcoder.com/practice/e2a22f0305eb4f2f9846e7d644dba09b?tpId=37&&tqId=21314&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking



```c++
#include<iostream> 
using namespace std; 
int pathNum(int n,int m)
{    
    if(n > 1 && m > 1)      
        
        return pathNum(n-1,m) + pathNum(n,m-1);  
    else if(((n >= 1)&&(m == 1))||((n == 1)&&(m >= 1)))    
        return n + m;    else      
            return 0;    
}


int main()
{    
    int n,m;  
    while(cin>>n>>m)    
    {    
        cout<<pathNum(n,m)<<endl;   
    
    }   
    return 0; 
}
 
```

