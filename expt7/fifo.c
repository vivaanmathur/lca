#include <stdio.h>
int main()
{
    int frame_size;
    printf("Enter frame size: ");
    scanf("%d", &frame_size);

    int frames[frame_size];
    for (int i = 0; i < frame_size; i++)
    {
        frames[i] = -1;
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

    int hits = 0, faults = 0, current = 0;

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
                break;
            }
        }
        if (found == 0)
        {
            frames[current] = val;
            current = (current + 1) % frame_size;
            faults++;
        }
    }

    printf("%d %d", hits, faults);
}