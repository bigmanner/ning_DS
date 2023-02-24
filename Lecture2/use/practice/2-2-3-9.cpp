//包含自定义头文件
#include"SeqListClass.h"

//包含系统头文件
#include<iostream>
#include<algorithm>
using namespace std;

int BinarySearch(int a[],int n,ElementTypeS x,int &insertLoc)
{
    //二分查找函数，insertLoc仅在返回值为-1时生效
    //返回的值是位序值，不是下标值
    int left=0;
    int right=n-1;//传入长度
    while(left<=right)
    {
        //只要left小于right，循环就能继续
        int mid=(left+right)/2;
        if(x==a[mid])
        {
            return mid+1;
        }
        if(x<a[mid])
        {
            right=mid-1;
            if(left>=right)
            {
                insertLoc=left+1;//+1代表位序
            }
            continue;
        }
        if(x>a[mid])
        {
            left=mid+1;
            if(left>=right)
            {
                insertLoc=right+1;//此处加一代表位序
            }
            continue;
        }
    }
    //如果跳出该循环，说明x不在这个数组里面，直接return -1即可
    return -1;
}
int main()
{
    //二分查找函数测试
    int a[10]={1,2,4,5,6,10,12,14,15,16};
    //sort(a,a+10);
    int insertLoc=-1;
    int findLoc=BinarySearch(a,10,3,insertLoc);
    cout<<"13的findLoc位置是"<<findLoc<<endl;
    cout<<"13的insertLoc是"<<insertLoc<<endl;
    return 0;
}