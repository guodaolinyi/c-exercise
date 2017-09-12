#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct SqList *List; //创建一个结构体指针类型 指向结构体 
struct SqList
{
    int Data[MAXSIZE];//建立数组  elementType是一个类型  elementType Data[MAXSIZE];
    int Last; //最后一个元素的位置 
} L; 


List MakeEmpty() ///初始化 建立空表 
{
    List list;
    list = (List)malloc(sizeof(struct SqList));
    list->Last = -1; //因为第一个元素是0，所以空表的最后一个元素就应该为-1
    return list; 
}

int Find(int X,List list)  //查找list中的某个元素 X的位置 
{
    int i = 0;
    while(i<=list->Last && list->Data[i]!=X ) //小于最后一个元素位置，并且没有和查找的元素相等，查找下一个 
    {
        i++;
    }
    if(i > list->Last)
    {
        return -1 ; //I已经大于最后一个元素的位置，说明没找到，返回-1 
    }
    else
    {
        return i ; //找到的位置 
    } 
}

void Insert(int X,int i,List list) //在第i个位置插入 
{
    int j;
    if(list->Last==MAXSIZE-1) //表满了 
    {
        printf("表已经满了");
        return; 
    }
    if(i<1||i>list->Last+2) //插入位置不对
    {
        printf("位置错误");
        return;
    }
    for(j=list->Last;j>=i-1;j--) //移动腾出空位 
    {
        list->Data[j+1] = list->Data[j];
    }
    list->Data[i-1] = X; //插入新元素 
    list->Last++; //指向新的最后一个元素位置 
    return;
} 

void Delete(int i, List list)
{
    int j;
    if(i<1||i>list->Last+1) //检查位置 
    {
        printf("不存在第%d个元素",i);
        return;
    }
    for(j=i;j<=list->Last;j++)
    {
        list->Data[j-1] = list->Data[j]; //向前移动补空位 
    }
    list->Last--; //指向新的最后一个元素位置
    return;
} 



int main()
{
    List list;
    list = MakeEmpty();
    int i;
    list->Last = 9 ;
    for(i = 0;i<10;i++)
    {
        list->Data[i] = i ;
    }
    for(i = 0;i<10;i++)
    {
        printf("第%d个数字是%d",i,i);
    }
}
