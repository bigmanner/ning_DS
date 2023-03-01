//包含自定义头文件
#include"CommonFunction.h"

//包含系统头文件
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

//全局变量
ComFunction comFunc;

int findMainElement(int a[],int n)
{
    //直接动态开辟一个数组
    int *kount=(int *)malloc(n*sizeof(int));
    int mostElem=-1;//初始化一个值
    //清空内存单元
    memset(kount,0,sizeof(kount));
    //进行一个桶排序
    for(int i=0;i<n;i++)
    {
        kount[a[i]]++;
    }
    int mostKount=-1;//寻找出现最多的个数
    for(int i=0;i<n;i++)
    {
        if(mostKount<kount[i])
        {
            mostKount=kount[i];
            mostElem=i;
        }
    }
    //一定要注意，动态开辟内存之后，一定要释放内存
    free(kount);
    if(mostKount>n/2)
        return mostElem;
    else
        return -1;
}

//Boyer-Moore投票算法
int findMainElement2(int a[],int n)
{
    comFunc.ArrayPrint(a,n);
    int mainElement=a[0];
    int kount=1;//Boyer-Moore算法所用计数器
    int rekount=0;//第二遍扫描整个数组的计数器
    cout<<"mainElement:\t"<<mainElement;
    cout<<"kount:"<<kount<<endl;
    for(int i=1;i<n;i++)
    {
        if(a[i]==mainElement)
        {
            kount++;
        }
        else
        {
            if(kount>1)
            {
                kount--;
            }
            else if(kount==1)
            {
                mainElement=a[i];
            }
        }
        cout<<"mainElement:\t"<<mainElement;
        cout<<"kount:"<<kount<<endl;
    }

    //重新扫描一遍整个数组，查看主元出现次数
    for(int i=0;i<n;i++)
    {
        if(mainElement==a[i])
        {
            rekount++;
        }
    }
    if(rekount>n/2)
        return mainElement;
    else
        return -1;
}

int main()
{
    int n=8;
    int A[8]={0,5,5,3,5,7,5,5};
    int B[8]={0,5,5,3,5,1,5,7};
    int result=findMainElement2(B,n);
    cout<<"数组的主元为"<<result<<endl;
    return 0;
}