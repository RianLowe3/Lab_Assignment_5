/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
char letter;
struct node* next;
} node;
// Returns number of nodes in the linkedList.
int length(node* head)
{
    int size = 0;
	
	while (head != NULL) 
	{
		size++;
		head = head->next;
	}
	return size;
}

char* toCString(node* head)
{
	int size = length(head);
	char* str = (char*)malloc(size + 1);
	int i = 0;
	while (head != NULL) 
	{
		
		str[i] = head->letter;
		head = head->next;
		i++;
	}
	
	str[size] = '\0';
	return str;
}
// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* newNode = (node*)malloc(sizeof(node));
	
	newNode->letter = c;
	newNode->next = NULL;
	
	if (*pHead == NULL) 
	{
		*pHead = newNode;
	}
	//Otherwise
	else 
	{
		node* currentnode = *pHead;
				while (currentnode->next != NULL)
		{
			currentnode = currentnode->next;
		}
	
		currentnode->next = newNode;
}
}
// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* currentnode = *pHead;
	while (currentnode != NULL)
	{
		
		node* temp = currentnode;
		currentnode = currentnode->next;
		free(temp);
	}
	
	*pHead = NULL;
}
int main(void)
{
int i, strLen, numInputs;
node* head = NULL;
char* str;
char c;
FILE* inFile = fopen("input.txt","r");
fscanf(inFile, " %d\n", &numInputs);
while (numInputs-- > 0)
{
fscanf(inFile, " %d\n", &strLen);
for (i = 0; i < strLen; i++)
{
fscanf(inFile," %c", &c);
insertChar(&head, c);
}
str = toCString(head);
printf("String is : %s\n", str);
free(str);
deleteList(&head);
if (head != NULL)
{
printf("deleteList is not correct!");
break;
}
}
fclose(inFile);
}
