#include <stdio.h>

#define NUMBER_OF_TRIES 10

int
random(void)
{
	// The computer returns a random number
	
	int rand = 5;

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
	
	int secret_number = random();
	int guess;
	int hit;

	print_header();               /* It print the header */

	for (register int i = 0, hit = 0; i < NUMBER_OF_TRIES && !hit; i++)
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
	}

	return 0;
}
