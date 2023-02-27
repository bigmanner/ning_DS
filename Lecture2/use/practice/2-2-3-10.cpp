//包含自定义头文件
#include"CommonFunction.h"

//包含系统头文件

//全局变量
ComFunction comFunc;        //内含常用函数


void ShiftArray(int i_targetArray[],int i_n,int i_shiftValue)
{

    //原理：(ab)->(a'b')->(a'b')'->(ba)
    //1.首先将前q个元素进行反转
    comFunc.ArrayReverse(i_targetArray,0,i_shiftValue-1);
    //2.再将剩余n-q个元素进行反转
    comFunc.ArrayReverse(i_targetArray,i_shiftValue,i_n-1);
    //3.将整体进行反转
    comFunc.ArrayReverse(i_targetArray,0,i_n-1);
}

int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    comFunc.ArrayPrint(a,10);
    ShiftArray(a,10,3);
    comFunc.ArrayPrint(a,10);
}