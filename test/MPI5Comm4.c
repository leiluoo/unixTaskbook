#include "ut1.h"
#include <mpi.h>

int main()
{
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	MPI_Group even;
	MPI_Comm even_comm;
	int color = rank % 2;
	MPI_Comm_split(MPI_COMM_WORLD, color, rank, &even_comm);

	if (rank % 2 == 0)
	{
		double nums[3];
		for (int i = 0; i < 3; ++i)
			GetD(&nums[i]);
		double result[3];
		MPI_Reduce(nums, result, 3, MPI_DOUBLE, MPI_MIN, 0, even_comm);
		if (rank == 0)
			for (int i = 0; i < 3; ++i)
				PutD(result[i]);
	}
	MPI_Finalize();
}