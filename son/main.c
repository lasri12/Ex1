#include<stdio.h>
#include<string.h>

int Count_Burn(char* p_char)
{
	if (NULL == p_char)
	{
		return 0;
	}
	int NUM_OF_FIRE = 0;
	for (int i = 0; i < strlen(p_char); i++)
	{
		if ('F' == p_char[i])
			NUM_OF_FIRE++;
	}
	return(NUM_OF_FIRE);
}
int main(int argc, char* argv[])
{
	exit(Count_Burn(argv[1]));
	
}