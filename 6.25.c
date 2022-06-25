//返回栈空间的地址的问题
#include <stdio.h>

char* GetMemory(void)
{
	static char p[] = "hello world";
	return p;
}
void Test(void)
{
	char *str = NULL;
	str = GetMemory();
	printf(str);//p的地址返回了，但是p指的内容在函数结束时销毁了
}
int main()
{
	Test();
	
	return 0;
}