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

void Reserve(List L, int K)
{
	if (K < 2)
		return;
	if (!L)
		return;
	List head = L;
	List prev = L->next;
	if (!prev)
		return;
	List pcur = prev->next;
	if (!pcur)
		return;
	int k = K - 2;
	while (pcur)
	{
		prev->next = pcur->next;
		pcur->next = head->next;
		head->next = pcur;
		pcur = prev->next;
		if (k)
		{
			k--;
		}
		else if(pcur&&k==0)
		{
			head = prev;
			prev = pcur;
			pcur = pcur->next;
			k = K - 2;
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
	List rear = (List)malloc(sizeof(struct Node));
	L->next = rear;
	rear->address = start_address;
	rear->data = a[start_address].data;
	rear->next = NULL;

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
	Reserve(L, 6);
	return 0;
}
