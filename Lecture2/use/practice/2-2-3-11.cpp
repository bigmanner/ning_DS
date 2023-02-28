//包含系统头文件
#include<iostream>
using namespace std;

int findMidNum(int a[],int b[],int n)
{
    int index_A=0;
    int index_B=0;
    int midValue=0;
    int kount=n;
    while(kount>0)
    {
        if(a[index_A]<b[index_B])
        {
            midValue=a[index_A];
            index_A++;
            kount--;
            continue;
        }
        if(a[index_A>b[index_B]])       
        {
            midValue=b[index_B];
            index_B++;
            kount--;
            continue;
        }
        if(a[index_A]==b[index_B])
        {
            midValue=a[index_A];
            index_A++;
            index_B++;
            kount-=2;
            continue;
        }
    }
    return midValue;
}

int main()
{
    int a[5]={11,13,15,17,19};
    int b[5]={2,4,6,8,20};
    int n=5;
    int result=findMidNum(a, b, n);
    cout<<"result is :"<<result<<endl;
    return 0;
}