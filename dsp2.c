#include <stdio.h>

char str[50], pat[20], rep[20], res[50];

void stringMatch()
{
    int i, j = 0, k, flag = 0;

    for (i = 0; str[i] != '\0'; )
    {
        for (k = 0; pat[k] != '\0'; k++)
        {
            if (str[i + k] != pat[k])
                break;
        }

        if (pat[k] == '\0')   // Pattern matched
        {
            flag = 1;
            for (k = 0; rep[k] != '\0'; k++)
                res[j++] = rep[k];

            i = i + k;   // Skip pattern
        }
        else
        {
            res[j++] = str[i++];
        }
    }

    res[j] = '\0';

    if (flag)
        printf("\nThe string after pattern match and replace is:\n %s", res);
    else
        printf("\nPattern string is not found");
}

void main()
{
    printf("Enter the main string: ");
    gets(str);

    printf("Enter the pat string: ");
    gets(pat);

    printf("Enter the replace string: ");
    gets(rep);

    printf("\nThe string before pattern match is:\n %s", str);

    stringMatch();
}
