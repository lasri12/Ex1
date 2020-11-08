#include "Father.h"

int main(int argc, char* argv[])
{
	FILE *p_input = NULL; errno_t err; char chunk[50]; int* forest_current; int* forest_next;
	if ((err = fopen_s(&p_input, argv[1], "r")) != 0)
	{
		printf("File was not opened\n");
		exit(999);
	}
	fgets(chunk, 50, p_input);
	int size_forest = atoi(chunk);
	forest_current = (char*)malloc(sizeof(char) * size_forest * size_forest );
	forest_next = (char*)malloc(sizeof(char) * size_forest * size_forest);
	fgets(chunk, 50, p_input);
	int num_of_iter = atoi(chunk);
	printf("%d, %d\n", size_forest, num_of_iter);
	fclose (p_input);
	free(forest_current);
	free(forest_next);
	return 0;
}