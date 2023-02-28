//包含系统头文件
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

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

int main()
{
    int n=8;
    int A[8]={0,5,5,3,5,7,5,5};
    int B[8]={0,5,5,3,5,1,5,7};
    int result=findMainElement(B,n);
    cout<<"数组的主元为"<<result<<endl;
    return 0;
}