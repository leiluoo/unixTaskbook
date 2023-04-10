
#include "ut1.h"
#include <mpi.h>
int main()
{
    MPI_Init(NULL, NULL);
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (!(rank % 2)) {
        int n;
        double num;
        double sum = 0;
        GetN(&n);
        for (int i = 0; i < n; ++i) {
            GetD(&num);
            sum += num;
        }
        PutD(sum);
    }
    MPI_Finalize();
}