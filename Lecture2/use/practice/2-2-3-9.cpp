//包含自定义头文件
#include"CommonFunction.h"

//包含系统头文件
#include<iostream>
using namespace std;

//全局变量
ComFunction comFunc;

bool exchangeOrInsert(int a[],int n,int searchElement)
{
    //如果能查找到元素，则和后继元素位置交换，如果找不到，插入到合适的位置
    //返回true表示查找到了元素，返回false表示没有查找到元素，并打算在合适的位置进行添加
    //利用二分查找T(n)=O(log2n)
    //接着继续吧
    int left=0;
    int right=n-1;
    int mid=0;
    int flag=0;             //用以指示最后一步是left=mid+1还是right=mid-1
    int insertIndex=-1;     //需要插入的位置
    while(left<=right)
    {
        mid=(left+right)/2;
        if(searchElement==a[mid])
        {
            //说明找到了,交换前后两个元素的位置
            if(n!=1&&mid!=n-1)
            {
                //如果交换前后两个元素，必须保证mid指示的元素不是最后一个或者只有一个元素
                int temp=0;
                temp=a[mid];
                a[mid]=a[mid+1];
                a[mid+1]=temp;
            }
            return true;
        }
        else if(searchElement<a[mid])
        {
            right=mid-1;
            flag=0;
        }
        else if(searchElement>a[mid])
        {
            left=mid+1;
            flag=1;
        }
    }
    //即使下标是-1或者n需要插入，都是需要满足的
    //这里right应该等于-1？？？
    if(flag==0)
    {
        insertIndex=right+1;
        //cout<<"flag为0，insertIndex值为"<<insertIndex<<endl;
    }
    else if(flag==1)
    {
        insertIndex=left;
        //cout<<"flag为1，insertIndex值为"<<insertIndex<<endl;
    }
    //依次向后移动元素
    for(int i=n-1;i>=insertIndex;i--)
    {
        a[i+1]=a[i];
    }
    a[insertIndex]=searchElement;
    return false;
}
int main()
{
    int A[10]={1,3,5,7,0,0,0,0,0,0};
    comFunc.ArrayPrint(A,4);
    int n=4;
    //int result=comFunc.ArrayBinarySearch(A,4,6);
    exchangeOrInsert(A,4,5);
    comFunc.ArrayPrint(A,5);
    //cout<<"二分查找结果为"<<result<<endl;
    return 0;
}