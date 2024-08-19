#include <stdio.h>
#include <ctype.h> //tolower
#include <stdlib.h>
#include <string.h>

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
		char * word = gen_random_word();
		printf("word: %s\n", word);
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

int main_loop()
{
	char * guess = (char *)malloc(10 * sizeof(char));

	return EXIT_SUCCESS;
}

void end_loop()
{

}

int main()
{
	//seed rand using time
	srand(time(NULL));

	init_loop();

	while ( main_loop() != EXIT_SUCCESS )
		main_loop();

	end_loop();

	return 0;
}
