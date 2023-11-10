#include<stdio.h>
#include<stdlib.h>

#define MAX_FRAMES 3

struct frame_entry
{
    int page_no;
    int referenced_by;
}FRAMES[MAX_FRAMES];

int main()
{
    int reference_string[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int len = (sizeof(reference_string) / sizeof(int));
    int page_hits = 0;
    int page_faults = 0;

    for(int i=0; i<MAX_FRAMES; i++)
    {
        FRAMES[i].page_no = -1;
        FRAMES[i].referenced_by = -1;
    }

    for(int i=0; i<len; i++)
    {
        int page_found = 0;
        int page = reference_string[i];

        for(int j=0; j<MAX_FRAMES; j++)
        {
            if(FRAMES[j].page_no == page && page_found == 0)
            {
                page_found = 1;
                FRAMES[j].referenced_by = i;
                page_hits++;
            }
        }

        if(page_found == 0)
        {
            for(int j=0; j<MAX_FRAMES; j++)
            {
                if(FRAMES[j].referenced_by == -1 && page_found == 0)
                {
                    FRAMES[j].page_no = page;
                    FRAMES[j].referenced_by = i;
                    page_found = 1;
                }
            }
        }

        if(page_found == 0)
        {
            page_faults++;
            int min = 0;
            for(int j=0; j<MAX_FRAMES; j++)
                if(FRAMES[j].referenced_by < FRAMES[min].referenced_by)
                    min = j;
            FRAMES[min].page_no = page;
            FRAMES[min].referenced_by = i;
            page_found = 1;
        }

        printf("\nCurrent Frames:\n");
        for(int j=0; j<MAX_FRAMES; j++)
        {
            if(FRAMES[j].page_no == -1)
                printf("[ ] ");
            else
                printf("[%d] ", FRAMES[j].page_no);
        }
    }
    printf("\n");

    return 0;
}