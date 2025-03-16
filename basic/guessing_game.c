#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main(void)
{
    srand(time(NULL));
    int randomNumber = rand() % 101;
    printf("Guess the number! it is between 1 and 100\n");
    int userGuess;
    char buffer[20];
    do
    {
        fgets(buffer, sizeof(buffer), stdin);

        // Clear the "\n" at the end of the buffer
        buffer[strcspn(buffer, "\n")] = 0;
        if (sscanf(buffer, "%d", &userGuess) == 1)
        {
            if (userGuess > 100 || userGuess < 1)
            {
                printf("Please enter something between 1 and 100\n");
                continue;
            }
        }
        else
        {
            printf("That is not a number!\n");
            continue;
        }
        if (userGuess < randomNumber)
        {
            printf("Guess something higher!\n");
        }
        else if (userGuess > randomNumber)
        {
            printf("Guess something lower!\n");
        }
    } while (userGuess != randomNumber);
    printf("You guessed right!\n");
}