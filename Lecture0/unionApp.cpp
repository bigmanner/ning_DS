//本题注意一定要吃掉空格getchar()

//引入头文件
#include<stdio.h>
#include<string.h>

//定义常量
#define TOTAL 4

//定义union和struct
union SC
{
    float score;            //成绩
    char course[20];        //课程
};

struct Information
{
    char name[20];          //名字
    int num;                //编号
    char sex;               //性别
    char profession;        //职业
    SC sc;                  //成绩和课程
};

//定义存储学生教师记录的数据结构
struct Information inf[TOTAL];

int main()
{
    //输入所有的四个数据
    for(int i=0;i<TOTAL;i++)
    {
        scanf("%s",inf[i].name);    //输入姓名
        scanf("%d",&(inf[i].num));  //输入编号
        getchar();                  //把空格吃掉
        scanf("%c",&(inf[i].sex));  //输入性别
        getchar();                  //吃掉空格
        scanf("%c",&(inf[i].profession));//输入职业
        if(inf[i].profession=='s')  //职业是学生
        {
            scanf("%f",&(inf[i].sc.score));//输入score的值
        }
        else
        {
            scanf("%s",inf[i].sc.course);
        }
    }

    //输出所有的四个数据
    for(int i=0;i<TOTAL;i++)
    {
        printf("第%d条记录：",i+1);
        printf("%s\t",inf[i].name);       //输出名字
        printf("%d\t",inf[i].num);        //输出编号
        printf("%c\t",inf[i].sex);        //输出性别
        printf("%c\t",inf[i].profession); //输出职位
        if(inf[i].profession=='s')
        {   //此时为学生
            printf("%f\n",inf[i].sc.score);//输出分数
        }
        else
        {
            //此时为老师
            printf("%s\n",inf[i].sc.course);//输出课程
        }
    }
    return 0;
}
