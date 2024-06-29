#pragma once

#define  LISTINCREMENT 10
#include <stdlib.h>
typedef struct Linear_list
{//unsigned int 类型的顺序表
public:
	unsigned int *elem;
	int length;
	int listSize;
	//Linear_list();

	
}SqList;


/*		顺序线性表初始化
* 说明:
* params: list_sq:线性表的引用，init_size:初始存储容量
* outputs: true:成功，false:失败
*/
bool InitList_Sq(Linear_list &list_sq,int init_size)
{
	list_sq.elem = (unsigned int *)malloc(init_size * sizeof(unsigned int));
	if(!list_sq.elem) 
		return false;
	list_sq.length = 0;
	list_sq.listSize = init_size;
	return true;

}


/*		顺序线性表中的第i个位置之前插入新的元素e
* 说明:
* params: list_sq:线性表的引用，init_size:初始存储容量
* outputs: true:成功，false:失败
*/
bool ListInsert_Sq(Linear_list &list_sq,int i,unsigned int elem_to_insert)
{
	if(i < 1 || i > list_sq.length+1)//! i的合法值为 1<=i<=length+1
		return false;
	if(list_sq.length >= list_sq.listSize)
	{
		unsigned int *newbase = (unsigned int*) realloc(list_sq.elem,(list_sq.length + LISTINCREMENT)*sizeof(unsigned int));
		if(!newbase)
			return false;
		list_sq.elem = newbase;
		list_sq.listSize += LISTINCREMENT;
	}
	//!插入
	//unsigned int *p;
	list_sq.elem[i-1] = elem_to_insert;
	for (int j = list_sq.length; j > i-1; j--)
	{
		list_sq.elem[j] = list_sq.elem[j-1];
	}
	list_sq.length++;
}

/*		获取顺序线性表中的第i个位置的元素的值
* 说明:
* params: list_sq:线性表的引用，nIndex:位置索引（从1开始）,value:取出的值
* outputs: true:成功，false:失败
*/
bool GetItem_Sq(const Linear_list &list_sq,int nIndex,unsigned int &value)
{
	if(nIndex < 1  || nIndex > list_sq.length)
		return false;
	value = list_sq.elem[nIndex-1];	
	return true;
}

/*		按值查找元素在顺序线性表中的位置
* 说明:
* params: list_sq:线性表的引用，value:元素的值
* outputs: int类型，代表元素在线性表中的位置（从1开始）
*/
int LocateItem_Sq(const Linear_list &list_sq,unsigned int value)
{
	for (int i = 0; i < list_sq.length; i++)
	{
		if(value == list_sq.elem[i])
			return ++i;
	}
	return -1;
	
}

/*		删除顺序线性表中的第i个位置的元素
* 说明:  删除后后面的元素全部往前移动一位
* params: list_sq:线性表的引用，nIndex:位置索引（从1开始）,value:取出的值
* outputs: true:成功，false:失败
*/
bool DeleteItem_Sq(Linear_list &list_sq,int nIndex)
{
	if(nIndex < 1  || nIndex > list_sq.length)
		return false;
	for (int i = nIndex; i < list_sq.length; i++)
	{
		list_sq.elem[nIndex-1] =  list_sq.elem[nIndex];
	}
	list_sq.length--;	
	return true;
}

//顺序表相关算法

void PrintList_sq(Linear_list L)
{
	for (int i = 0; i < L.length; i++)
	{
		std::cout<<L.elem[i];
		if (i != (L.length-1))
		{
			std::cout<<",";
		}
		else
		{
			std::cout<<".";
		}	
	}
	std::cout<<std::endl;
}



/*		合并顺序表A和B
* 说明:  从B中依次取出元素，若在A中没有找到该元素，则插入
* params: list_sq:线性表的引用
* outputs: 无
*/
void MergeList_sq(Linear_list& list_A,Linear_list& list_B)
{
	int m = list_A.length;
	int n = list_B.length;
	unsigned int value = 0;
	for (int i = 0; i < n; i++)
	{
		GetItem_Sq(list_B,i+1,value);
		if (LocateItem_Sq(list_A,value) == -1)
		{
			ListInsert_Sq(list_A,++m,value);
		}
		
	}
	
}


/*		合并顺序有序表A和B
* 说明:  A,B都为非递减有序的顺序表，合并后相同元素不删除
* params: list_sq:线性表的引用
* outputs: 无
*/
void MergeSqList_sq(Linear_list& LA,Linear_list& LB,Linear_list& LC)
{
	unsigned int *pa,*pb,*pc;
	int m = LA.length;
	int n = LB.length;
	//①创建一个长度为m+n的空表LC
	LC.length = m + n;
	LC.elem = new unsigned int[LC.length];
	//②初始化分别指向三个表第一个元素的指针pa,pb,pc
	pc = LC.elem;
	pa = LA.elem;
	pb = LB.elem;
	//③当pa和pb均未到达队尾时，比较pa和pb指向的元素，将较小的插入pc后面
	while (pa <= (LA.elem + LA.length -1) && pb <= (LB.elem + LB.length -1))
	{
		if (*pa <= *pb)
		{
			*pc++ = *pa++;
		}
		else
		{
			*pc++ = *pb++;
		}
	}
	//④当pa或pb到达队尾时，将剩下的一方所有结点依次插入到pc后面
	while (pa <= (LA.elem + LA.length -1))
	{
		*pc++ = *pa++;
	}
	while (pb <= (LB.elem + LB.length -1))
	{
		*pc++ = *pb++;
	}
}