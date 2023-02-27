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