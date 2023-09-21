#include "main.h"

/**
 * stripWhitespace - Removes leading and trailing whitespaces and reduces
 * multiple spaces between tokens to a single space.
 *
 * @line: Pointer to the string to be stripped.
 */
void stripWhitespace(char *line)
{
    if (line == NULL)
        return;

    int length = strlen(line);
    int start = 0;
    int end = length - 1;
    int i, j;
    int insideToken = 0;

    // Remove leading whitespaces
    while (isspace(line[start]))
        start++;

    // Remove trailing whitespaces
    while (end >= start && isspace(line[end]))
        end--;

    // Remove multiple spaces between tokens
    for (i = start, j = start; i <= end; i++)
    {
        if (isspace(line[i]))
        {
            if (!insideToken)
            {
                line[j++] = ' ';
                insideToken = 1;
            }
        }
        else
        {
            line[j++] = line[i];
            insideToken = 0;
        }
    }

    // Null-terminate the stripped string
    line[j] = '\0';

    // Shift the stripped content to the beginning of the string
    memmove(line, line + start, j - start + 1);
}
