//引入自定义头文件
#include"CommonFunction.h"

//引入系统头文件
#include<iostream>
using namespace std;
//类成员函数定义实现

//1.
bool ComFunction::ArrayReverse(int i_targetArray[],int i_from,int i_to)
{
    //1.判断逆转的坐标是否正确
    if(i_from>i_to)
    {
        //如果from大于to，则该函数不正确
        return false;
    }

    //2.若下标正确，则进行逆转
    int mid=(i_from+i_to)/2;
    int temp=0;             //用于交换
    int n=i_to-i_from+1;    //用于计算需交换元素的个数

    //这样进行前后交换即可
    for(int i=0;i<=mid;i++)
    {
        temp=i_targetArray[i];
        i_targetArray[i]=i_targetArray[n-i-1];
        i_targetArray[n-i-1]=temp;
    }
    return true;
}

//2.
void ComFunction::ArrayPrint(int i_targetArray[],int i_n)
    {
        cout<<"该数组打印为："<<endl;
        for(int i=0;i<i_n;i++)
        {
            cout<<i_targetArray[i]<<"\t";
        }
        cout<<endl;
    }

//3.
int ComFunction::ArrayBinarySearch(int i_targetArray[],int i_length,int i_searchElement)
{
    //二分查找
    int left=0;
    int right=i_length-1;
    int mid=-1;
    while(left<=right)
    {
        mid=(left+right)/2;//计算中间下标
        if(i_searchElement==i_targetArray[mid])
        {
            return mid;
        }
        if(i_searchElement<i_targetArray[mid])
        {
            right=mid-1;
        }
        if(i_searchElement>i_targetArray[mid])
        {
            left=mid+1;
        }
    }
    return -1;
}

/*
//测试成员函数
int main()
{
    ComFunction comFunc;
    int A[4]={3,4,5,6};
    int n=4;
    int indexOfTarget=comFunc.ArrayBinarySearch(A,4,6);
    cout<<"二分查找结果为"<<indexOfTarget<<endl;
    return 0;
}
*/