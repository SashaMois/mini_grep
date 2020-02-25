#include <stdio.h>

#define MAXLINE 10000
#define NO -1

/*
 * input every string from its input data to meet specific pattern - 
 * the given string of characters.
 */

int getline(char line_for_save_input[]);
int strindex(char line_for_search[]);

char pattern[] = "ould";

int main()
{
    char line[MAXLINE]; 
    char save_line[MAXLINE]; /* save truth strings */
    int found = 0; /* count of founded characters */
    int i = 0;

    while (getline(line) != 0) {
        if (strindex(line) > 0) {
            ++found;

            for (int j = 0; line[j] != '\n'; ++j, ++i)
                save_line[i] = line[j];
            save_line[i++] = '\n';
        }
    }
    save_line[i] = '\0';

    printf("\n%s", save_line);

    return found;
}

int getline(char line[])
{
    int c; /* for save input characters */
    int i = 0; /* count */
    int lim = MAXLINE; /* limit for input characters */

    while ((c = getchar()) != EOF && c != '\n' && --lim > 0)
        line[i++] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';

    return i;
}

int strindex(char line[])
{ 
    int i, k, j; /* count */

    for (i = 0; line[i] != '\0'; ++i) {
        for (k = i, j = 0; pattern[j] != '\0' && line[k] == pattern[j]; ++j, ++k)
            ;
        if (j > 0 && pattern[j] == '\0')
            return i;
    }
    return NO;

}