#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void shift(char **arr, int n)
{
    free(arr[0]);
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
}
int main(int argc, char const *argv[])
{
    const int bufsiz = 4000;
    int n = 10;
    int numArg = 0;
    FILE *f = stdin;
    if (argc > 1)
    {
        char *s;
        for (int i = 1; i < argc; i++)
        {
            s = malloc(strlen(argv[i]) + 1);
            strcpy(s, argv[i]);
            if (strcmp(s, "-n") == 0)
            {
                numArg = 1;
            }
            else if (strcmp(s, "-h") == 0)
            {
                printf("Jsem napomocna napoveda\n");
            }
            else if (strcmp(s, "--help") == 0)
            {
                printf("Jsem napomocna napoveda\n");
            }
            else
            {
                if (s[0] == '-')
                {
                    strcpy(&s[0], &s[1]);
                    numArg = 1;
                }

                if (numArg)
                {
                    n = atoi(s);
                    numArg = 0;
                }
                else
                {
                    f = fopen(s, "r");
                }
            }
            free(s);
        }
    }
    char **lines = malloc(n * sizeof(char *));
    char buffer[bufsiz];
    int last = 0;
    for (int i = 0; fgets(buffer, bufsiz - 1, f) != NULL;)
    {

        if (i >= n)
        {
            shift(lines, i);
            lines[i - 1] = malloc(strlen(buffer) + 1);
            strcpy(lines[i - 1], buffer);
        }
        else
        {

            lines[i] = malloc(strlen(buffer) + 1);
            strcpy(lines[i], buffer);
            last = i;
            i++;
        }
    }
    for (int i = 0; i <= last; i++)
    {
        printf(lines[i]);
        free(lines[i]);
    }
    fclose(f);
    free(lines);

    return 0;
}
