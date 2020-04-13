#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

long row_sum (int ** array, long size)
{ 
	long s = 0;
	for(long i=0;i <size;i++) 
		for ( long j= 0 ; j < size ; j++)
			s += array[i][j]; 
	return s;
}

int main() 
{
	int ** array = (int **)calloc (1024,sizeof(int*));
	for ( int i = 0 ; i  < 1024 ; i ++ )
	{
		array[i] = (int *) calloc (1024,sizeof(int*));
		for ( int j = 0 ; j  < 1024 ; j ++ ) array[i][j] = i;
	}
	row_sum(array,1024);
	free (array);
	return 0;
}
