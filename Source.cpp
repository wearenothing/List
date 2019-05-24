#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	int next;
};

typedef struct Node
{
	int address;
	int data;
	struct Node* next;
}Node,*List;

void Reserve(List L)
{

}
void ReserveK(List L, int K)
{
	List front, rear;
	front = rear = L;
	while (true)
	{
		int k = K;
		while (rear->next&&k)
		{
			rear = rear->next;
			k--;
		}
		if (k == 0)
		{

		}
		else
		{
			break;
		}
	}
}
int main()
{
	node a[100000];
	int start_address, N, K;
	cin >> start_address >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		cin >> a[k].data >> a[k].next;
	}

	List L = (List)malloc(sizeof(struct Node));
	L->address = start_address;
	L->data = a[start_address].data;
	L->next = NULL;
	List rear = L;
	while (true)
	{
		List S = (List)malloc(sizeof(Node));
		S->address = a[rear->address].next;
		if (S->address == -1)
			break;
		S->data = a[S->address].data;
		S->next = NULL;
		rear->next = S;
		rear = S;
	}
	return 0;
}