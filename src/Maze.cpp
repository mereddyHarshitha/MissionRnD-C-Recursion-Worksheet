/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>

int find_path(int *maze, int rows, int columns, int x1, int y1, int x2, int y2){

	if (x1 >= rows || y1 >= columns || x2 >= rows || y2 >= columns)
		return 0;

	int xdiff, ydiff,temp=0;
	
	if (x1 - x2 < 0)
		xdiff = x2 - x1;
	else
		xdiff = x1 - x2;

	if (y1 - y2 < 0)
		ydiff = y2 - y1;
	else
		ydiff = y1 - y2;

	int p = maze[x1*columns + y1];
	int q = maze[x2*columns + y2];

	if (p == 1 && q == 1){
		if (xdiff == 0 && ydiff == 1 || xdiff == 1 && ydiff == 0)
			temp = 1;
	}

	return temp;
}
int path_exists_wrapper(int *maze, int rows, int columns, int x1, int y1, int x2, int y2,int position){

	if (find_path(maze, rows, columns, x1, y1, x2, y2))
		return 1;

	int right = find_path(maze, rows, columns, x1, y1, x1, y1 + 1);
	int left = find_path(maze, rows, columns, x1, y1, x1, y1 - 1);
	int top = find_path(maze, rows, columns, x1, y1, x1 - 1, y1);
	int down = find_path(maze, rows, columns, x1, y1, x1 + 1, y1);

	if ( right && position != 3)
		return path_exists_wrapper(maze, rows, columns, x1, y1 + 1, x2, y2, 1);

	if ( down && position != 4)
		return path_exists_wrapper(maze, rows, columns, x1+1, y1, x2, y2, 2);

	if ( left && position != 1)
		return path_exists_wrapper(maze, rows, columns, x1, y1-1, x2, y2, 3);

	if ( top && position != 2)
		return path_exists_wrapper(maze, rows, columns, x1-1, y1 , x2, y2, 4);

	return 0;
}

int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (rows < 0 || columns < 0|| x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0)
		return 0;

	return path_exists_wrapper(maze,rows,columns,x1,y1,x2,y2,0);
}
