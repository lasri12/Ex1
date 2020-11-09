#ifndef Father_h
#define Father_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Fire_Check(int i, int j, char* forest_current, char* forest_next, int dimension);
void file_2_arr(FILE* file, char* forest_current, int dimen);
void simulation(int dimen, int iteration_num, char* forest_cur, char* forest_next, FILE* p_out);


#endif