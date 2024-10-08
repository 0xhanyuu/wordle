#include <stdio.h>
#include <ctype.h> //tolower
#include <stdlib.h>
#include <string.h>
#include <time.h>

char * dictionary[3] = { "cat", "dog", "word" };

char * gen_random_word()
{
	//init nullptr
	char * str = NULL;
	//pick word from dictionary
	int word_value = rand() % 3;
	//realloc
	str = realloc(str, strlen(dictionary[word_value]));
	//set word
	memcpy(str, dictionary[word_value], strlen(dictionary[word_value]));

	return str;
}

void init_loop()
{
	char choice;
start:
	system("clear");
	printf("hello! welcome to wordle\n");
	printf("would you like to:\n");
	printf("start [1]	quit [2]\n");
	printf("input: ");
	scanf("%c", &choice);
	switch(choice)
	{
		case '1':
		break;

		case '2':
		exit(0);
		break;

		default:
		printf("invalid choice!\n");
		goto start;
		break;
	}
}

int main_loop(char * word, int word_size)
{
	char guess[word_size];
	printf("%s\n", "input a guess:");
	scanf("%s", guess);

	if ( strcmp(guess, word) == 0 )
		return EXIT_SUCCESS;
	else
		return EXIT_FAILURE;
}

void end_loop()
{
	//
}

int main()
{
	//seed rand using time
	srand(time(NULL));

	init_loop();

	char * word = gen_random_word();
	int word_size = strlen(word);

	while ( main_loop(word, word_size) != EXIT_SUCCESS )
		main_loop(word, word_size);

	end_loop();

	return 0;
}
