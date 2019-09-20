#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n = 10;
    int numArg = 0;
    FILE *f;
    if (argc > 1)
    {
        for (size_t i = 1; i < argc; i++)
        {
            char *s = (char *)malloc(strlen(argv[i]));
            strcpy(s, argv[i]);
            if (strcmp(s, "-n") == 0)
            {
                numArg = 1;
                free(s);
                continue;
            }
            else if (strcmp(s, "-h") == 0)
            {
                printf("Jsem napomocna napoveda");
            }
            else if (strcmp(s, "--help") == 0)
            {
                printf("Jsem napomocna napoveda");
            }

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
                f = freopen(s, "r", stdin);
            }
            free(s);
        }
    }
    const int buffsize = 4096;
    char buffer[buffsize];
    for (size_t i = 0; i < n && fgets(buffer, buffsize - 1, stdin) != NULL; i++)
    {
        printf("%s", buffer);
    }
    fclose(f);
    return 0;
}
