#include "ut1.h"
int main()
{
    MPI_Init(NULL, NULL);

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank % 2 == 0) {
        int n;
        GetN(&n);
        PutN(2 * n);
    }
	MPI_Finalize();
}