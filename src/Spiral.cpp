/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>


int *show_spiral(int **input_array, int *index, int *res_array, int *r_strt, int *r_end, int *c_strt, int *c_end){

	int p = *index;
	int i;
	int a = *r_strt;
	int b = *c_strt;
	int c = *r_end;
	int d = *c_end;

	for (i = b; i < d; ++i){
		res_array[p++] = input_array[a][i];
	}
	a++;

	for (i = a; i < c; ++i){
		res_array[p++] = input_array[i][d - 1];
	}
	d--;

	if (a < c){
		for (i = d - 1; i >= b; --i){
			res_array[p++] = input_array[c - 1][i];
		}
		c--;
	}

	if (b < d){
		for (i = c - 1; i >= a; --i){
			res_array[p++] = input_array[i][b];
		}
		b++;
	}

	if (a < c && b < d)
		return show_spiral(input_array, &p, res_array, &a, &c, &b, &d);
	else
		return res_array;
}

int *spiral(int rows, int columns, int **input_array)
{
	if (rows <= 0 || columns <= 0 || input_array == NULL)
		return NULL;

	int *res_array = (int*)calloc(rows*columns, sizeof(int));

	int index = 0;
	int r_strt = 0, c_strt = 0;
	int r_end = rows;
	int c_end = columns;

	res_array = show_spiral(input_array, &index, res_array, &r_strt, &r_end, &c_strt, &c_end);

	return res_array;
	
}
