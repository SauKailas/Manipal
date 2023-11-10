#include<stdio.h>
#include<stdlib.h>

#define MAX_FRAMES 3

struct frame_entry
{
	int page_no;
	int referenced_by;
	int lives;
};

int main()
{
	int reference_string[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int len = sizeof(reference_string) / sizeof(reference_string[0]);
    struct frame_entry FRAMES[3];

    for(int i=0; i<MAX_FRAMES; i++)
    {
    	FRAMES[i].page_no = -1;
    	FRAMES[i].referenced_by = -1;
    	FRAMES[i].lives = 1;
    }

    for(int i=0; i<len; i++)
    {
    	int page = reference_string[i];
    	int page_found = 0;

    	for(int j=0; j<MAX_FRAMES; j++)
    	{
    		if(page_found == 0 && FRAMES[j].page_no == page)
    		{
    			FRAMES[j].referenced_by = i;
    			FRAMES[j].lives = 1;
    			page_found = 1;
    		}
    	}

    	if(page_found == 0)
    	{
    		for(int j=0; j<MAX_FRAMES; j++)
    		{
    			if(page_found == 0 && FRAMES[j].page_no == -1)
    			{
    				FRAMES[j].page_no = page;
    				FRAMES[j].referenced_by = i;
    				FRAMES[j].lives = 1;
    				page_found = 1;
    			}
    		}
    	}

    	if(page_found == 0)
    	{
    		STEP_BACK:

    		for(int j=0; j<MAX_FRAMES; j++)
    		{
    			if(page_found == 0 && FRAMES[j].lives == 1)
    				FRAMES[j].lives--;
    			else if(page_found == 0 && FRAMES[j].lives == 0)
    			{
    				FRAMES[j].page_no = page;
    				FRAMES[j].referenced_by = i;
    				FRAMES[j].lives = 1;
    				page_found = 1;
    			}
    		}
    		if(page_found == 0)
    			goto STEP_BACK;
    		else
    			goto STEP_FRONT;
    	}

    	STEP_FRONT:

    	printf("\nCurrent Frames:\n");
    	for(int j=0; j<MAX_FRAMES; j++)
    	{
    		if(FRAMES[j].page_no == -1)
    			printf("[ ]");
    		else
    			printf("[%d]", FRAMES[j].page_no);
    	}
    	printf("\n");
    }

    return 0;
}