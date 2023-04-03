#include "ut1.h"

// int main()
// {
//     MPI_Init(NULL, NULL);
//     int rank, size;
//     MPI_Comm_size(MPI_COMM_WORLD, &size);
//     MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//     int n;

//     if (!rank) {
//         for (int i = 1; i < size; ++i) {
//             MPI_Recv(&n, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//             PutN(n + 1);
//         }
//     }
//     else {
//         GetN(&n);
//         MPI_Send(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
//         if (rank == 1)
//             PutN(n);
//     }
// 	MPI_Finalize();
// }

int main()
{
    MPI_Init(NULL, NULL);
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int n;

    if (!rank) {
        for (int i = 1; i < size; ++i) {
            MPI_Recv(&n, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            PutN(n);
        }
    }
    else {
        GetN(&n);
        MPI_Send(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
	MPI_Finalize();
}