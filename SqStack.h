#pragma once
#include <iostream>
#define MAXSIZE 100
/**顺序栈的数据结构**/
typedef struct SqStack
{
    unsigned int *base;//栈底指针，为null时表示栈不存在
    unsigned int *top;//栈顶指针,指向栈顶元素后一位
    int stackSize;
}SqStack;



/*		顺序栈初始化
* 说明:  ①为顺序栈动态分配一个最大容量为MAXSIZE的数组空间，使base指向这段空间的基地址，即栈底
        ②栈顶指针top初始化为base，表示栈为空
        ③stacksize置为栈的最大容量MAXSIZE
* params: sqS:线性栈的引用
* outputs: true:成功，false:失败
*/
bool InitStack(SqStack &sqS)
{
    sqS.base = new unsigned int[MAXSIZE];
    if(!sqS.base)
        return false;
    sqS.top = sqS.base;
    sqS.stackSize = MAXSIZE;
    return true;
}


/*		入栈操作
* 说明:  ①判断栈是否为满
        ②将新元素压入栈顶，栈顶指针加一
* params: sqS:线性栈的引用
* outputs: true:成功，false:失败
*/
bool Push_sqStack(SqStack &S,unsigned int value)
{
    if(!S.base || !S.top)
        return false;
    if((S.top - S.base) >= MAXSIZE)
        return false;
    *S.top++ = value;
    return true;
}


/*		出栈操作
* 说明:  ①判断栈是否为空
        ②栈顶指针减一,栈顶元素出栈
* params: sqS:线性栈的引用
* outputs: true:成功，false:失败
*/
bool Pop_sqStack(SqStack &S,unsigned int &value)
{
    if(!S.base || !S.top)
        return false;
    if(S.top == S.base)
        return false;
    value = *--S.top;
}


/*		取栈顶元素
* 说明:  ①判断栈是否为空
        ②取栈顶元素，栈顶指针不变
* params: sqS:线性栈的引用
* outputs: true:成功，false:失败
*/
unsigned int GetTop_sqStack(SqStack S)
{
    if(!S.base || !S.top)
        return false;
    if(S.top == S.base)
        return false;
    return *(S.top-1);
}