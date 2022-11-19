#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_TRIES 10
#define MAX_SCORE 1000

int
randm(void)
{
	// The computer returns a random number
	
	int seconds = time(0);               /* It get the second current since 1th january 1970 */
	srandom(seconds);                    /* It changes the seed */

	int rand = random() % 10;            /* It calculates the new random number */

	return rand;
}

void
print_header(void)
{
	// Print the header of the game
	
	printf("********************************\n");
	printf("* Welcome to the guessing game *\n");
	printf("********************************\n");
}

int
get_number(void)
{
	int guess;

	printf("Type your guess: ");
	scanf("%d", &guess);

	return guess;
}

int
main(void)
{
	// Variables
	
	float score = MAX_SCORE;
	int guess;
	int hit;
	int secret_number = randm();

	print_header();               /* It print the header */

	for (register short i = 0, hit = 0; i < NUMBER_OF_TRIES && !hit; i++)
	{
		guess = get_number();            /* It gets the guess of the user */

		if (guess < 0)
		{
			i--;
			continue; 		 /* Negative numbers aren't allowed */
		}
		else if (guess > secret_number)
			printf("You guess was higher than the secret number. Try again!\n");
		else if (guess < secret_number)
			printf("You guess was lower than the secret number. Try again!\n");
		else if (guess == secret_number)
		{
			printf("You tried %d times to get it right!\n", ++i);
			hit = 1;
		}

		score -= (float) abs(guess - secret_number) / 2;
	}

	printf("Score: %.1f\n", score);             /* Print the score on default output */

	return 0;
}
