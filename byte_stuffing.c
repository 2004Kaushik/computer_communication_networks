#include<stdio.h>
#include<string.h>

char input[100];
char arr[100] = "DLESTX";
char rec[100];
int i,j,k;
char ch;

int main()
{
    printf("\n Enter the stream to be byte stuffed :");
    scanf("%s",input);
    int l = strlen(input);
    for(i = 0,j = 6; i < l;i++)
    {
        if((input[i] == 'D') & (input[i+1] == 'L') & input[i+2] == 'E')
        {
            arr[j++] = input[i];
            arr[j++] = input[i+1];
            arr[j++] = input[i+2];
            arr[j++] = 'D';
            arr[j++] = 'L';
            arr[j++] = 'E';
            i = i + 2;
        }
        else
        {
            arr[j++] = input[i];
        }
    }
    strcat(arr,"DLEETX");
    j = strlen(arr);
    printf("\n The byte stuffed string is :");
    for(i = 0; i < j; i++)
    {
        ch = arr[i];
        printf("%c",ch);
    }
    printf("\n The destuffed string is :");
    //Destuffing
    j = 6;
    k = strlen(arr);
    for(j = 6; j < k - 6; j++)
    {
        if((arr[j] == 'D') & (arr[j+1] == 'L') & (arr[j+2] == 'E'))
        {
            j = j + 2;
            printf("DLE");
            j = j + 3;
        }
        else
        {
            ch = arr[j];
            printf("%c",ch);
        }
    }
}
