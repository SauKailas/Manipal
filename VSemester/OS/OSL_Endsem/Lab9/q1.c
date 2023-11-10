#include<stdio.h>
#include<stdlib.h>

struct MemoryBlock
{
	int size;
	int allocated;
	struct MemoryBlock *next;
};

struct MemoryBlock *createBlock(int size)
{
	struct MemoryBlock *block = (struct MemoryBlock*)malloc(sizeof(struct MemoryBlock));
	block->size = size;
	block->allocated = 0;
	block->next = NULL;
	return block;
}

struct MemoryBlock *createMemory(struct MemoryBlock *memory, int size)
{
	struct MemoryBlock *block = createBlock(size);

	if(memory == NULL)
		return block;
	else
	{
		struct MemoryBlock *curr = memory;
		while(curr->next != NULL)
			curr = curr->next;
		curr->next = block;
		return memory;
	}
}

void printMemory(struct MemoryBlock *memory)
{
	if(memory == NULL)
		printf("Memory EMPTY!\n");
	else
	{
		struct MemoryBlock *curr = memory;
		while(curr != NULL)
		{
			printf("Size: %d\tAllocated: %d\n", curr->size, curr->allocated);
			curr = curr->next;
		}
	}
}

struct MemoryBlock *firstFit(struct MemoryBlock *memory, int size)
{
	struct MemoryBlock *curr = memory;

	while(curr != NULL)
	{
		if(curr->allocated == 0 && curr->size >= size)
		{
			curr->allocated = 1;
			return curr;
		}
		curr = curr->next;
	}
	return NULL;
}

struct MemoryBlock *bestFit(struct MemoryBlock *memory, int size)
{
	struct MemoryBlock *curr = memory;
	struct MemoryBlock *bestFitBlock = NULL;

	while(curr != NULL)
	{
		if(curr->allocated == 0 && curr->size >= size)
			if(bestFitBlock == NULL || curr->size < bestFitBlock->size)
				bestFitBlock = curr;
		curr = curr->next;
	}

	if(bestFitBlock != NULL)
	{
		bestFitBlock->allocated = 1;
		return bestFitBlock;
	} 
	return NULL;
}

struct MemoryBlock *worstFit(struct MemoryBlock *memory, int size)
{
	struct MemoryBlock *curr = memory;
	struct MemoryBlock *worstFitBlock = NULL;

	while(curr != NULL)
	{
		if(curr->allocated == 0 && curr->size >= size)
			if(worstFitBlock == NULL || curr->size > worstFitBlock->size)
				worstFitBlock = curr;
		curr = curr->next;
	}

	if(worstFitBlock != NULL)
	{
		worstFitBlock->allocated = 1;
		return worstFitBlock;
	}
	return NULL;
}

void deallocateMemory(struct MemoryBlock *memory)
{
	struct MemoryBlock *curr = memory;

	while(curr != NULL)
	{
		curr->allocated = 0;
		curr = curr->next;
	}
}

int main()
{
	struct MemoryBlock *memory = NULL;

	memory = createMemory(memory, 20);
	memory = createMemory(memory, 15);
	memory = createMemory(memory, 10);
	memory = createMemory(memory, 40);
	memory = createMemory(memory, 50);

	printf("\nCurrent Memory:\n");
	printMemory(memory);

	struct MemoryBlock *block1 = firstFit(memory, 10);
	printf("\nFirst Fit Allocation:\n");
	printMemory(memory);
	deallocateMemory(memory);

	struct MemoryBlock *block2 = bestFit(memory, 10);
	printf("\nBest Fit Allocation:\n");
	printMemory(memory);
	deallocateMemory(memory);

	struct MemoryBlock *block3 = worstFit(memory, 10);
	printf("\nWorst Fit Allocation:\n");
	printMemory(memory);
	deallocateMemory(memory);

	printf("\n\n");

	return 0;
}