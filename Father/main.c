#define _CRT_SECURE_NO_WARNINGS
#include "Father.h"

void Fire_Check(int i, int j, char* forest_current[], char* forest_next[], int dimension)
{
	int trigger = 0;
	if (i != 0)
	{
		if (forest_current[i - 1][j] == 'F')
		{
			trigger = 1;
		}
	}
	if (i != dimension - 1)
	{
		if (forest_current[i + 1][j] == 'F')
		{
			trigger = 1;
		}
	}
	if (j != 0)
	{
		if (forest_current[i][j - 1] == 'F')
		{
			trigger = 1;
		}
	}
	if (j != dimension - 1)
	{
		if (forest_current[i][j+1] == 'F')
		{
			trigger = 1;
		}
	}
	if (trigger == 1)
	{
		forest_next[i][j] = 'F';
	}
	else
	{
		forest_next[i][j] = 'T';
	}
	return;
}

void Ground_Check(int i, int j, char* forest_current[], char* forest_next[], int dimension)
{
	int counter = 0;
	if (i != 0)
	{
		if (forest_current[i - 1][j] == 'F')
		{
			counter++;
		}
		if (j != 0)
		{
			if (forest_current[1]);
		}
	}
}

void file_2_arr(FILE *file,char *forest_current,int dimen)
{
	char *buffer = NULL;
	buffer =(char*)malloc(sizeof(char) *dimen);
	const char* delim = ",";
	while (fgets(buffer, sizeof buffer, file))
	{
		char* token = strtok(buffer, delim);
		while (token != '\n')
		{
			for (int i = 0; i < dimen; i++)
			{
				for (int j = 0; j < dimen; j++)
				{
					*(forest_current + i * dimen + j)= token;
					
				}
			}
		}
	}
	for (int i = 0; i < dimen; i++)
	{
		for (int j = 0; j < dimen; j++)
		{
			printf("%c,", (forest_current + i * dimen + j));
		}
	}
	return;
}
int main(int argc, char* argv[])
{
	FILE *p_input = NULL; errno_t err; char chunk[50]; char* forest_current; char* forest_next;
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
	file_2_arr(p_input, forest_current, size_forest);


	fclose (p_input);
	free(forest_current);
	free(forest_next);
	return 0;
}