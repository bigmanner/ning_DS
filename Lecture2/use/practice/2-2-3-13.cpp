//Q:找出数组中未出现的最小整数

//包含自定义头文件
#include"CommonFunction.h"

//包含系统头文件
#include<string.h>
#include<iostream>
using namespace std;

//宏定义
#define MAXN 100

//全局变量
ComFunction comfunc;
int positive[MAXN+10];

//1.暴力求解方法。T(n)=O(n^2)
int findMinPositive1(int a[],int n)
{
    int kount=1;//定义最小的初始值为1
    
    for(int i=0;i<n;i++)
    {
        if(kount==a[i])
        {
            i=0;//从头开始检查
            kount++;
        }
    }
    //一旦跳出循环，说明kount即为最小的正数
    return kount;
}

//2.利用经典计数器原理，T(n)=O(n),S(n)=O(n)
int findMinPositive2(int a[],int n)
{
    //初始化数组元素为0
    memset(positive,0,sizeof(positive));
    int minPos=n+1;         //用以返回的最小正数值
    for(int i=0;i<n;i++)
    {
        //只有值大于0的时候，a[i]才能当作下标来访问positive数组
        if(a[i]>0)
            positive[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(positive[i]==0)
        {
            minPos=i;
            break;
        }
    }
    return minPos;
}

int main()
{
    int a[4]={-5,1,2,3};
    int n=4;
    int minPos=findMinPositive2(a,n);
    cout<<"最小正数即为"<<minPos<<endl;
    return 0;
}