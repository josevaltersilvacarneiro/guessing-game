#include <stdio.h>

void
print_header(void)
{

	// Print the header of the game
	
	printf("#######################################\n");
	printf("Welcome to the guessing game\n");
	printf("#######################################\n");

}

int
main(void)
{
	// Variables
	
	int secret_number = 42;

	// Start
	
	print_header();

	return 0;
}
