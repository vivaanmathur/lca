#include <stdio.h>

int main()
{
    int frame_size;
    printf("Enter frame size: ");
    scanf("%d", &frame_size);

    int frames[frame_size];
    int last_used[frame_size];

    for (int i = 0; i < frame_size; i++)
    {
        frames[i] = -1;
        last_used[i] = -1;
    }

    int no_of_ref;
    printf("Enter no. of references: ");
    scanf("%d", &no_of_ref);

    int pages[no_of_ref];

    printf("Enter the reference string: ");

    for (int i = 0; i < no_of_ref; i++)
    {
        scanf("%d", &pages[i]);
    }

    int hits = 0, faults = 0;

    for (int i = 0; i < no_of_ref; i++)
    {
        int found = 0;
        int val = pages[i];

        for (int j = 0; j < frame_size; j++)
        {
            if (frames[j] == val)
            {
                found = 1;
                hits++;
                last_used[j] = i;
                break;
            }
        }

        if (found == 0)
        {
            int lru_index = 0;

            for (int j = 1; j < frame_size; j++)
            {
                if (last_used[j] < last_used[lru_index])
                {
                    lru_index = j;
                }
            }

            frames[lru_index] = val;
            last_used[lru_index] = i;
            faults++;
        }
    }

    printf("Hits: %d\nFaults: %d\n", hits, faults);

    return 0;
}