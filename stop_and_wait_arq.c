#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

#define w 1

int main()
{
    srand(time(0));
    int f,frames[50],i;
    printf("\n Enter the number of frames :");
    scanf("%d",&f);

    printf("\n Enter the frames :");
    for(i = 0; i < f; i++)
    {
        scanf("%d",&frames[i]);
    }

    printf("\n In stop and wait ARQ, window size is 1 and we send 1 frame at a time");
    for(i = 0; i < f; i++)
    {
        if(rand()%2 == 1)
        {
            if(i % w == 0)
            {
                printf("\n Frame %d sent successfully",i);
                printf("\n Acknowledgement received for frame %d",i);
            }
            else
            {
                printf("\n Frame %d sent successfully",i);
            }
        }
        else
        {
            sleep(3);
            printf("\n Error detected. Resending frame %d...",i);
            i = i - 1;

        }
    }
}
