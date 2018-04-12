#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0
#define ARRAYSIZE 10

typedef int SElemType;
typedef char Status;

typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack &S) {
	//构建一个空栈
	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}//InitStack

Status GetTop(SqStack S, SElemType &e) {
	//若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR
	if (S.top == S.base)
		return ERROR;
	e = *(S.top - 1);
	return OK;
}//GetTop

Status Push(SqStack &S, SElemType e) {
	if (S.top - S.base >= S.stacksize) {
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base)
			exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}//Push

Status Pop(SqStack &S, SElemType &e) {
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}//Pop

Status StackEmpty(SqStack S) {
	if (S.top == S.base)
		return TURE;
	else
		return FALSE;
}

Status AllVrackets_Test(char *str)
{
	int i, n = 0;
	char a[ARRAYSIZE], ch;
	SqStack S;
	InitStack(S);
	for(p = str; *p; p++){
		if (*p == '(' || *p == '[' || '{')
			Push(S, *p);
		else if(*p == ')' || ']' || '}')
		{
			if (StackEmpty(S))
				return ERROR;
			Pop(S, c);
			if (*p == ')' && c != '(')
				return ERROR;
			if (*p == ']' && c != '[')
				return ERROR;
			if (*p == '}' && c != '{')
				return ERROR;
		}
	}
	if (!StackEmpty(S))
		return ERROR;
	return OK;
}

int main()
{
	char str[10], enter;
	SqStack S;
	InitStack(S);
	printf("请输入字符串：\n");
	scanf("%s", str);
	scanf("%c"; &enter);
	AllVrackets_Test(str);
	return 0;
}