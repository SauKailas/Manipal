#include<stdio.h>
#include<stdlib.h>

struct Process
{
	int id;
	int priority;
	int burst_time;
};

struct Queue
{
	int front, rear, size;
	struct Process **processes;
};

struct Process *createProcess(int id, int priority, int burst_time)
{
	struct Process *process = (struct Process*)malloc(sizeof(struct Process));
	process->id = id;
	process->priority = priority;
	process->burst_time = burst_time;
	return process;
}

struct Queue *createQueue(int size)
{
	struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->processes = (struct Process*)malloc(size*sizeof(struct Process));
	queue->front = queue->rear = -1;
	queue->size = size;
	return queue;
}

void Enqueue(struct Queue *queue, struct Process *process)
{
	if(queue->rear == queue->size-1)
	{
		printf("Queue is FULL!\n");
		return;
	}
	else
	{
		if(queue->front == -1)
			queue->front = 0;
		queue->rear++;
		queue->processes[queue->rear] = process;
	}
}

struct Process *Dequeue(struct Queue *queue)
{
	if(queue->front == -1)
	{
		printf("Queue is EMPTY!\n");
		return NULL;
	}
	else
	{
		struct Process *ret = queue->processes[queue->front];
		if(queue->front == queue->rear)
			queue->front = queue->rear = -1;
		else
			queue->front++;
		return ret;
	}
}

int main()
{
	struct Queue *q1 = createQueue(100);
	struct Queue *q2 = createQueue(100);
	struct Queue *q3 = createQueue(100);

	struct Process *p1 = createProcess(1, 1, 10);
	struct Process *p2 = createProcess(2, 2, 15);
	struct Process *p3 = createProcess(3, 3, 8);

	Enqueue(q1, p1);
	Enqueue(q2, p2);
	Enqueue(q3, p3);

	struct Process *curr;

	curr = Dequeue(q1);
	printf("Processing process %d with FCFS!\n", curr->id);

	curr = Dequeue(q2);
	printf("Processing process %d with Priority Scheduling!\n", curr->id);

	curr = Dequeue(q3);
	printf("Processing process %d with Round Robin!\n", curr->id);

	return 0;
}