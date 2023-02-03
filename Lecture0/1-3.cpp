#include<iostream>
#include<string.h>

using namespace std;

int a[10];//定义a的数组

int maxSubSeqSum1(int a[],int n)
{
    //变量定义
    int maxValue=0;     //用于返回最终的结果
    int tempSum=0;      //用于计算临时的加和

    for(int i=0;i<=n-1;i++)//前面的指针
    {
        for(int j=i;j<=n-1;j++)
        {
            tempSum=0;
            for(int k=i;k<=j;k++)
            {
                tempSum+=a[k];
            }
            if(maxValue<tempSum)
                maxValue=tempSum;
        }
    }
    return maxValue;
}

int maxSubSeqSum2(int a[],int n)
{
    int tempSum=0;//临时存储所有的加和
    int maxSum=0;//存储最大的加和
    for(int i=0;i<=n-1;i++)
    {
        tempSum=0;//做一个初始化的刷新
        for(int j=i;j<=n-1;j++)
        {
            tempSum+=a[j];
            if(maxSum<tempSum)
                maxSum=tempSum;
        }
    }
    return maxSum;
}

int maxSubSeqSum3(int a[],int left,int right)
{
    if(left==right)
    {
        return a[left];
    }
    int mid=0;//中间下标值
    mid=(left+right)/2;
    int leftmax=0;//数列左侧最大值
    int rightmax=0;//数列右侧最大值
    
    int templeft=0;//数列左侧的累加求和
    int tempright=0;//数列右侧的累加求和

    int maxmid=0;
    int maxleft=0;
    int maxright=0;

    leftmax=maxSubSeqSum3(a,left,mid);//左侧最大值递归求解
    rightmax=maxSubSeqSum3(a,mid+1,right);//右侧最大值递归求解

    for(int i=mid;i>=left;i--)
    {
        templeft+=a[i];
        if(maxleft<templeft)
            maxleft=templeft;
    }

    for(int j=mid+1;j<=right;j++)
    {
        tempright+=a[j];
        if(maxright<tempright)
            maxright=tempright;
    }
    maxmid=maxleft+maxright;

    int finalMax=0;
    finalMax=finalMax<maxleft?maxleft:finalMax;
    finalMax=finalMax<maxright?maxright:finalMax;
    finalMax=finalMax<maxmid?maxmid:finalMax;
    return finalMax;
}

//在线算法
int maxSubSeqSum4(int a[],int n)
{
    int tempSum=0;//临时求和
    int maxSum=0;//最大求和
    for(int i=0;i<n;i++)
    {
        tempSum+=a[i];//加上最新的元素
        if(maxSum<tempSum)
            maxSum=tempSum;
        if(tempSum<0)
            tempSum=0;
    }
    return maxSum;

}

int main()
{
    memset(a,0,sizeof(a));
    int n=0;      //代表需要排序的数列个数
    int result1=0; //定义结果
    int result2=0; //定义结果
    int result3=0; //定义结果
    int result4=0; //定义结果
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    result1=maxSubSeqSum1(a,n);
    result2=maxSubSeqSum2(a,n);
    result3=maxSubSeqSum3(a,0,n-1);
    result4=maxSubSeqSum4(a,n);
    cout<<"result1 is :"<<result1<<endl;
    cout<<"result2 is :"<<result2<<endl;
    cout<<"result3 is :"<<result3<<endl;
    cout<<"result4 is :"<<result4<<endl;
    return 0;
}