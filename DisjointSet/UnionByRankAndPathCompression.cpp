/*
Given an array A[] that stores all number from 1 to N (both inclusive and sorted) and K queries.

The task is to do the following operations on array elements :

1. UNION X Z : Perform union of X and Z i.e. parent of Z will become the parent of X.
2. FIND X: Find the parent of X and print it.

Note: Initially all are the parent of themselves.

*/

int find(int A[],int X) // Function to find the parent of the node given
{
    if(X == A[X])
    return X;
    
    return A[X] = find(A, A[X]);
}

void unionSet(int A[],int X,int Z) //Function to return the union of the two nodes
{
	X = find(A, X);
	Z = find(A, Z);
	A[X]=Z;
}
