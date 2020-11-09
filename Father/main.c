#define _CRT_SECURE_NO_WARNINGS
#include "Father.h"

void Fire_Check(int i, int j, char* forest_current, char* forest_next, int dimension)
{
	int trigger = 0;
	if (i != 0)
	{
		if (forest_current[(i - 1) * dimension + j] == 'F')	//check above
		{
			trigger = 1;
		}
	}
	if (i != dimension - 1)
	{
		if (forest_current[(i + 1) * dimension + j] == 'F')	//check below
		{
			trigger = 1;
		}
	}
	if (j != 0)
	{
		if (forest_current[i * dimension + j - 1] == ' F')		//check left
		{
			trigger = 1;
		}
	}
	if (j != dimension - 1)
	{
		if (forest_current[i * dimension + j + 1] == 'F')		//check right
		{
			trigger = 1;
		}
	}
	if (trigger == 1)
	{
		forest_next[i * dimension + j] = 'F';
	}
	else
	{
		forest_next[i * dimension + j] = 'T';
	}
	return;
}

void Ground_Check(int i, int j, char* forest_current, char* forest_next, int dimension)
{
	int counter = 0;
	if (i != 0)
	{
		if (forest_current[(i - 1) * dimension + j] == 'T')		//check above		
		{
			counter++;
		}
		if (j != 0)
		{
			if (forest_current[(i - 1) * dimension + j - 1] == 'T')		//check up left
			{
				counter++;
			}
		}
		if (j = !dimension - 1)
		{
			if (forest_current[(i - 1) * dimension + j + 1] == 'T')		//check up right
			{
				counter++;
			}
		}
	}
	if (j != 0)
	{
		if (forest_current[i*dimension + j - 1] == 'T')				//check left
		{
			counter++;
		}
		if (i != dimension - 1)
		{
			if (forest_current[(i + 1) * dimension + j - 1] == 'T')		//check left down
			{
				counter++;
			}
		}
	}
	if (i != dimension - 1)
	{
		if (forest_current[(i + 1) * dimension + j] == 'T')		//check down
		{
			counter++;
		}
		if (j != dimension - 1)
		{
			if (forest_current[(i + 1) * dimension + j + 1] == 'T')		//check right down
			{
				counter++;
			}
		}
	}
	if (j != dimension - 1)
	{
		if (forest_current[i * dimension + j + 1] == 'T')		//check right
		{
			counter++;
		}
	}
	if (counter > 1)
	{
		forest_next[i*dimension +j] = 'T';
	}
	else
	{
		forest_next[i*dimension +j] = 'G';
	}
	return;
}

void file_2_arr(FILE* file, char* forest_current, int dimen)
{

	while (1) {
		int chr = fgetc(file);
		if (chr == EOF)
			break;

		switch (chr) {
		case ',':
		case '\n':
			break;
		default:
			*forest_current++ = chr;
			break;
		}
	}

#if 0
	* forest_current = 0;
#endif
}

int main(int argc, char* argv[])
{
	FILE* p_input = NULL; errno_t err; char chunk[50]; char* forest_current; char* forest_next; char* p_temp;
	int iter_counter = 0;
	int i = 0, j = 0;
	if ((err = fopen_s(&p_input, argv[1], "r")) != 0)
	{
		printf("File was not opened\n");
		exit(999);
	}
	fgets(chunk, 50, p_input);
	int size_forest = atoi(chunk);
	forest_current = (char*)malloc(sizeof(char) * size_forest * size_forest );
	if (NULL == forest_current)
	{
		printf("allocate did not succeed");
		exit(2);
	}
	forest_next = (char*)malloc(sizeof(char) * size_forest * size_forest);
	if (NULL == forest_current)
	{
		printf("allocate did not succeed");
		exit(2);
	}
	fgets(chunk, 50, p_input);
	int num_of_iter = atoi(chunk);
	file_2_arr(p_input, forest_current, size_forest);
	

	for (iter_counter = 0; iter_counter < num_of_iter; iter_counter++)	//	start iter
	{
		
		for (i = 0; i < size_forest; i++)		//run on lines
		{
			for (j = 0; j < size_forest; j++)		//run on col
			{
				if (forest_current[i * size_forest + j] == 'G')
				{
					Ground_Check(i, j, forest_current, forest_next, size_forest);
				}
				else if (forest_current[i * size_forest + j] == 'F')
				{
					forest_next[i * size_forest + j] = 'G';
				}
				else if (forest_current[i * size_forest + j] == 'T')
				{
					Fire_Check(i, j, forest_current, forest_next, size_forest);
				}
				//
				printf("i=%d, j=%d, current letter=%c, next_letter=%c\n", i, j, forest_current[i * size_forest + j], forest_next[i * size_forest + j]);
				//
			}
		}
		p_temp = forest_current;
		forest_current = forest_next;
		forest_next = p_temp;
	}


	fclose (p_input);
	free(forest_current);
	free(forest_next);
	return 0;
}