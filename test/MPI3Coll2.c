#include "ut1.h"

int main()
{
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	double numbers[5];
	if (rank == 0)
		for (int i = 0; i < 5; ++i)
			GetD(&numbers[i]);
	MPI_Bcast(&numbers, 5, MPI_DOUBLE, rank, MPI_COMM_WORLD);
	if (rank != 0)
		for (int i = 0; i < 5; ++i)
			PutD(numbers[i]);

	MPI_Finalize();
}
