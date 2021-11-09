#include<stdio.h>
#include<malloc.h> 
#include<windows.h>
#define LIST_INIT_SIZE 100 //���Ա�洢�ռ�ĳ�ʼ������
#define LIST_INCREMENT 10 //���Ա�洢�ռ�ķ�������

typedef int ElemType;      //����Ԫ�ص����ͣ�������int�͵�

typedef struct{
    ElemType *elem;       //�洢�ռ�Ļ���ַ
    int length;      //��ǰ���Ա�ĳ���
    int listsize;    //��ǰ����Ĵ洢����
}SqList;
//�������Ա�
int InitList(SqList &L)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));//����һ���洢�ռ䣬�������洢�ռ�Ļ���ַ��ֵ��elem
    if (!L.elem)
    {
        return -1; //�ռ����ʧ��
    }
    L.length = 0; //��ǰ����
    L.listsize = LIST_INIT_SIZE; //��ǰ������
    return 0;
}
//����Ԫ��
int InserElement(SqList &L,int i,ElemType e)
{
    if(i<1||i>L.length+1)
        return -1;
    if(L.length >= L.listsize)
    {
        ElemType *newbase = (ElemType *)realloc(L.elem, (L.listsize + LIST_INCREMENT)*sizeof(ElemType));
        if (!newbase) return -1;//�洢�ռ����ʧ��
        L.elem = newbase;//�»�ַ
        L.listsize += LIST_INCREMENT;//���Ӵ洢����
    }
    //�������
    ElemType *q, *p; //����2��ָ�����
    q = &(L.elem[i-1]); //qΪ����λ��(ע���β�i����ţ�����ǴӴ�1��ʼ�ģ����±��Ǵ�0��ʼ�ģ��������ת���±����i-1)
    for (p = &(L.elem[L.length - 1]); p >= q; --p) //��ai��an-1���κ��ƣ�ע����Ʋ���Ҫ�Ӻ���ǰ����
    {
        *(p + 1) = *p;
    }
    *q = e;
    ++L.length;//����1
    return 0;
}

//ɾ��Ԫ��
int ListDelete(SqList &L, int i, ElemType &e)
{
    //�ж�ɾ��λ�õĺϷ���
    if (i<1 || i>L.length) return -1;
    //ɾ������
    ElemType *q, *p;//����2��ָ�����
    p = &(L.elem[i - 1]);//pΪ��ɾ��Ԫ�ص�λ��(ע���β�i����ţ�����ǴӴ�1��ʼ�ģ����±��Ǵ�0��ʼ�ģ��������ת���±����i-1)
    e = *p; //��ɾ����Ԫ�ظ�ֵ��e(�����ò�����Ҳ�����õ������Ա����e��)
    q = L.elem + L.length - 1;//qָ���β���һ��Ԫ��(q�����һ��Ԫ�صĵ�ַ)
    for (++p; p <= q; ++p) //��p����һ��Ԫ�ؿ�ʼ����ǰ��
    {
        *(p - 1) = *p;
    }

    --L.length;//����1
    return 0;
}
//��ӡ���Ա�
int toString(SqList L)
{
    for(int i=0;i<L.length;i++)
    {
        printf("%d ",L.elem[i]);
    }
    printf("\n");
}
//��λĿ��Ԫ��
int LocateElem(SqList L, ElemType x)
{
    int pos = -1;
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == x)
        {
            pos = i;
        }
    }
    return pos;
}
int main()
{
    SqList list;
    InitList(list);

    for(int i=1;i<=10;i++)
    {
        InserElement(list,i,i);
    }

    toString(list);

    int e;

    ListDelete(list,2,e);

    toString(list);

    printf("��ɾ����Ԫ��e=%d",e);


}

