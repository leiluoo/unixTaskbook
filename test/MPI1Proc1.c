
#include "ut1.h"
#include <mpi.h>
int main()
{
    MPI_Init(NULL, NULL);
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    double n;
    GetD(&n);
    PutD(-n);
    ShowD(-n);
    MPI_Finalize();
}