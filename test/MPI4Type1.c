#include "ut1.h"
#include <mpi.h>

int main()
{
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	MPI_Datatype newtype;
	MPI_Type_contiguous(3, MPI_INT, &newtype);
	MPI_Type_commit(&newtype);

	int *numbers = (int*)malloc((size - 1) * 3 * sizeof(int));

	if (rank == 0)
		for (int i = 0; i < (size - 1) * 3; ++i)
			GetN(&numbers[i]);

	MPI_Bcast(numbers, size - 1, newtype, 0, MPI_COMM_WORLD);
	if (rank != 0)
		for (int i = 0; i < (size - 1) * 3; ++i)
			PutN(numbers[i]);

	MPI_Type_free(&newtype);
	free(numbers);
	numbers = NULL;
	MPI_Finalize();
}

