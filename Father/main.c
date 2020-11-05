#include<stdio.h>
#include<string.h>


int main(int argc, char* argv[])
{
	FILE *p_input = NULL; errno_t err; char size='\0'; int* forest_current; int* forest_next;
	char num_of_iter='\0';
	int iter;
	if ((err = fopen_s(&p_input, argv[1], "r")) != 0)
	{
		printf("File was not opened\n");
	}
	fgets(size, 1, p_input);
	forest_current = (int*)malloc(sizeof(int) * atoi(size) * atoi(size));
	forest_next = (int*)malloc(sizeof(int) * atoi(size) * atoi(size));
	fgets(num_of_iter, 1, p_input);
	iter = atoi(num_of_iter);
	printf("%d\n", iter);
	
}