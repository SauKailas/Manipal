#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct DSA
{
	int request_id;
	int arrival_timestamp;
	int cylinder;
	int address;
	int process_id;
};

void FCFS(struct DSA *requests, int n)
{
	int current_cylinder = 0;
	int total_head_movements = 0;

	int visited[n];
	for(int i=0; i<n; i++)
		visited[i] = 0;

	printf("\n\nFCFS SCHEDULING ORDER:\n\n");

	for(int i=0; i<n; i++)
	{
		int min_timestamp = 100000;
		int next_request = -1;
		int current_cylinder = 0;

		for(int j=0; j<n; j++)
		{
			if(visited[j] == 0)
			{
				int time = requests[j].arrival_timestamp;
				if(time < min_timestamp)
				{
					min_timestamp = time;
					next_request = j;
				}
			}
		}

		visited[next_request] = 1;
		printf("Request ID: %d\tCylinder: %d\tProcess ID: %d\n", requests[next_request].request_id, requests[next_request].cylinder, requests[next_request].process_id);
		total_head_movements += abs(current_cylinder - requests[next_request].cylinder);
		current_cylinder = requests[next_request].cylinder;
	}
	printf("Total Head Movements: %d\n", total_head_movements);
}

void SSTF(struct DSA *requests, int n)
{
	int current_cylinder = 0;
	int total_head_movements = 0;

	int visited[n];
	for(int i=0; i<n; i++)
		visited[i] = 0;

	printf("\n\nSSTF SCHEDULING ORDER:\n\n");

	for(int i=0; i<n; i++)
	{
		int min_distance = 100000;
		int next_request = -1;

		for(int j=0; j<n; j++)
		{
			if(visited[j] == 0)
			{
				int distance = abs(current_cylinder - requests[next_request].cylinder);
				if(distance < min_distance)
				{
					min_distance = distance;
					next_request = j;
				}
			}
		}

		visited[next_request] = 1;
		printf("Request ID: %d\tCylinder: %d\tProcess ID: %d\n", requests[next_request].request_id, requests[next_request].cylinder, requests[next_request].process_id);
		total_head_movements += min_distance;
		current_cylinder = requests[next_request].cylinder;
	}
	printf("Total Head Movements: %d\n", total_head_movements);
}

int main()
{
	int n;
	printf("Enter the number of disk requests: ");
	scanf("%d", &n);

	struct DSA *requests = (struct DSA*)malloc(sizeof(struct DSA));

    printf("Enter disk requests in the format: RequestID ArrivalTimestamp Cylinder Address ProcessID\n");
    for (int i=0; i<n; i++)
        scanf("%d %d %d %d %d", &requests[i].request_id, &requests[i].arrival_timestamp, &requests[i].cylinder, &requests[i].address, &requests[i].process_id);

    FCFS(requests, n);
    SSTF(requests, n);

    return 0;
}