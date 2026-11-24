#include <stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct
{
	int front;
	int rear;
	int num;
	int deque[10001];

}Deque;

void push(Deque* s, char cmd[])
{
	int x;
	if (cmd[5] == 'f')//push_front 실행
	{
		scanf("%d", &x);
		
		
		s->deque[s->front--] = x;
		if (s->front == -1)s->front = 10000;
		s->num++;
	}
	else//push_back 실행
	{
		scanf("%d", &x);
	
		
		s->deque[s->rear++] = x;
		if (s->rear == 10001)s->rear = 0;
		s->num++;
	}	
}

int pop(Deque* s, char cmd[])
{
	int temp;
	if (cmd[4] == 'f')//pop_front 실행
	{
		if (s->num == 0)
			return -1;
		else
		{
			if (s->front == 10000)s->front = -1;
			temp = s->deque[++s->front];
			s->num--;
			return temp;
		}

	}
	else //pop_back 실행
	{
		if (s->num == 0)
			return -1;
		else
		{
			if (s->rear == 0)s->rear = 10001;
			temp = s->deque[--s->rear];
			s->num--;
			return temp;
		}
	}
}

int size(Deque* s)
{
	return s->num;
}
int empty(Deque* s)
{
	return s->num == 0 ? 1 : 0;
}
int front(Deque* s)
{
	if (s->num == 0)return -1;
	else if (s->front == 10000)return s->deque[0];
	else
		return s->deque[s->front + 1];
}
int back(Deque* s)
{
	
	if (s->num == 0)return -1;
	else if (s->rear == 0)return s->deque[10000];
	else
		return s->deque[s->rear - 1];
}

int main()
{
	Deque s;
	s.front = 10000, s.rear = 0, s.num = 0;
	int n;
	char cmd[20];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", cmd);
		if (strncmp("push", cmd, 4) == 0)
			push(&s, cmd);
		else if (strncmp("pop", cmd, 3) == 0)
			printf("%d\n", pop(&s, cmd));
		else if (strcmp("size", cmd) == 0)
			printf("%d\n",size(&s));
		else if (strcmp("empty", cmd) == 0)
			printf("%d\n",empty(&s));
		else if (strcmp("front", cmd) == 0)
			printf("%d\n",front(&s));
		else if (strcmp("back", cmd) == 0)
			printf("%d\n",back(&s));
	}
	return 0;

}