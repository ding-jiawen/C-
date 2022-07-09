//链表：头部插入一个节点
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};
struct Node* head;//全局变量

void HeadInsert(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));//为新创建的节点分配内存空间
	temp -> data = x;
	temp -> next = NULL;//16-19行也简写：temp->next = head;
	if(head != NULL)
	{
		temp -> next = head;//新创建的节点链接到上一个节点地址
	}
	head = temp;//head指向新创建的节点
}

void PrintList()
{
	struct Node* temp = head;
	printf("List is:");
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;//temp节点往后走
	}
	printf("\n");
}
	
int main()
{
	head = NULL;
	printf("How many numbers?\n");
	int n, i, x;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		printf("Enter the number:\n");
		scanf("%d", &x);
		HeadInsert(x);
		PrintList();
	}
	return 0;
}
		
