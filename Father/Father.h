#ifndef Father_h
#define Father_h


#define TIMEOUT_IN_MILLISECONDS 5000
#define BRUTAL_TERMINATION_CODE 0x55

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

BOOL CreateProcessSimple(LPTSTR CommandLine, PROCESS_INFORMATION* ProcessInfoPtr);
void CreateProcessSimpleMain(char* p_2_string, int dimen, FILE* p_out);
void Fire_Check(int i, int j, char* forest_current, char* forest_next, int dimension);
void file_2_arr(FILE* file, char* forest_current, int dimen);
void simulation(int dimen, int iteration_num, char* forest_cur, char* forest_next, FILE* p_out);


#endif