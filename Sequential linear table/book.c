#include <stdio.h>
#define  MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];
    int last;
}Seqlist;
int Locate(Seqlist L,ElemType e)
{
    int i=0;
    while((i<=L.last)&&(L.elem[i]!=e))
        i++;
    if(i<=L.last)
        return (i+1);
    else
        return (-1);
}
#define OK 1
#define ERROR 0
int InsList(Seqlist * L, int i,ElemType e)
{
    int k;
    if((i<1)||(i>L->last+2))
    {
        printf("插入位置i值不合法");
        return (ERROR);
    }
    for(k=L->last;k>=i-1;k--)
        L->elem[k+1]=L->elem[k];
    L->elem[i-1]=e;
    L->last++;
    return (OK);
}
int DelList(Seqlist * L, int i,ElemType *e)
{
    int k;
    if ((i<1)||(i>L->last+1))
    {
        printf("删除位置不合法");
        return (ERROR);
    }
    *e=L->elem[i-1];
    for (k=i;k<=L->last;k++)
    {
        L->elem[k-1]=L->elem[k];
        L->last--;
        return (OK);
    }
}
void mergeList(Seqlist * LA,Seqlist * LB,Seqlist * LC)
{
    int i,j,k,l;
    i=0;j=0;k=0;
    while (i<=LA->last&&j<=LB->last)
        if(LA->elem[i]<=LB->elem[j])
        {
            LC->elem[k]=LA->elem[i];
            i++;k++;
        } else {
            LC->elem[k]=LB->elem[j];
            j++;k++;
        }
    while (i<=LA->last)
    {
        LC->elem[k]=LA->elem[i];
        i++;k++;
    }
    while (j<=LB->last)
    {
        LC->elem[k]=LB->elem[j];
        i++;k++;
    }
    LC->last=LA->last+LB->last+1;
}
void main()
{
    Seqlist L={{1,2,3,4,5,6,7,8,9},7};
    int m;
    m=Locate(L,8);
    if(m==-1)printf("不存在");
    else printf("找到在 %d 的位置",m);
}