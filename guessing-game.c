#include <stdio.h>

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

	print_header();                  /* It print the header */
	guess = get_number();            /* It gets the guess of the user */

	if (guess > secret_number)
		printf("You guess was higher than the secret number. Try again!\n");
	else if (guess < secret_number)
		printf("You guess was lower than the secret number. Try again!\n");
	else
		printf("You guessed right!\n");

	return 0;
}
