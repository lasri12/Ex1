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
		if (forest_current[i * dimension + j - 1] == 'F')		//check left
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
		if (j != dimension - 1)
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
}

void simulation(int dimen,int iteration_num, char* forest_cur, char* forest_next,FILE *p_out)
{
	char* p_temp; int k=0;
	for (int iter_counter = 0; iter_counter < iteration_num; iter_counter++)	//	start iter
	{
		for (int i = 0; i < dimen; i++)		//run on lines
		{
			for (int j = 0; j < dimen; j++)		//run on col
			{
				if (forest_cur[i * dimen + j] == 'G')
				{
					Ground_Check(i, j, forest_cur, forest_next, dimen);
				}
				else if (forest_cur[i * dimen + j] == 'F')
				{
					forest_next[i * dimen + j] = 'G';
				}
				else
				{
					Fire_Check(i, j, forest_cur, forest_next, dimen);
				}
			}
		}
		while (k < dimen * dimen)
		{
			fputc(forest_cur[k], p_out);
			k++;
		}
		k = 0;
		fputs(" - ", p_out);// to add number of firesssssss
		fputs("\n", p_out);
		p_temp = forest_cur;
		forest_cur = forest_next;
		forest_next = p_temp;
	}
	return;
}
int main(int argc, char* argv[])
{
	FILE* p_input = NULL; FILE* p_output=NULL;errno_t err; char chunk[50]; char* forest_current; char* forest_next;
	int iter_counter = 0;
	if ((err = fopen_s(&p_input, argv[1], "r")) != 0)
	{
		printf("File was not opened\n");
		exit(999);
	}
	fgets(chunk, 50, p_input);
	int size_forest = atoi(chunk);
	forest_current = (char*)malloc(sizeof(char) * (size_forest * size_forest));
	if (NULL == forest_current)
	{
		printf("allocate did not succeed");
		exit(2);
	}
	forest_next = (char*)malloc(sizeof(char) * (size_forest * size_forest));
	if (NULL == forest_current)
	{
		printf("allocate did not succeed");
		exit(2);
	}
	fgets(chunk, 50, p_input);
	int num_of_iter = atoi(chunk);
	file_2_arr(p_input, forest_current, size_forest);
	p_output = fopen("output.txt", "w");
	if (p_output == NULL)
	{
		printf("output file didn't open\n");
		exit(2);
	}
	simulation(size_forest, num_of_iter, forest_current, forest_next, p_output);
	

	fclose (p_input);
	fclose(p_output);
	free(forest_current);
	free(forest_next);
	return 0;
}