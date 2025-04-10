#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 1000
char plain[40], cipher[40];
int key;

int main()
{
    printf("\n Enter the plain text :");
    fgets(plain, MAX, stdin);

    // Entering the key
    printf("\n Enter the key by which we encrypt :");
    scanf("%d", &key);
    while (1)
    {
        if ((key < 1) || (key > 26))
        {
            printf("\n Bad request. Try again");
        }
        else
        {
            break;
        }
    }
    int i;
    char ch;
    for (i = 0; i < strlen(plain); i++)
    {
        if (isalpha(plain[i]))
        {
            ch = toupper(plain[i]);
            cipher[i] = ((ch - 'A') + key) % 26 + 'A';
        }
        else
        {
            continue;
        }
    }
    printf("The encrypted text is %s", cipher);

    // Decryption
    printf("\n Enter the key for decryption :");
    scanf("%d", &key);
    for (i = 0; i < strlen(cipher); i++)
    {
        if (isalpha(cipher[i]))
        {
            ch = toupper(cipher[i]);
            plain[i] = ((ch - 'A') - key + (26)) % 26 + 'A';
        }
    }
    printf("\n Decrypted text is %s:", plain);
    return 0;
}
