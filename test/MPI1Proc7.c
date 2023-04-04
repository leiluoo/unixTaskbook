
#include "ut1.h"
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
        if (rank == 0)
            //PutD(sum+1);
        else 
            PutD(sum);
    }
    MPI_Finalize();
}


// #include "ut1.h"
// int main()
// {
//     MPI_Init(NULL, NULL);
//     int rank, size;
//     MPI_Comm_size(MPI_COMM_WORLD, &size);
//     MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//     if (rank == 0) {
//         int n;
//         double num;
//         double sum = 0;
//         GetN(&n);
//         for (int i = 0; i < n; ++i) {
//             GetD(&num);
//             sum += num;
//         }
//         PutD(sum + 1);
//     }

//     if (rank == 1) {
//         int n;
//         double num;
//         double sum = 0;
//         GetN(&n);
//         for (int i = 0; i < n; ++i) {
//             //GetD(&num);
//             sum += num;
//         }
//         PutD(sum);
//     }

//     if (rank == 2) {
//         int n;
//         int num;
//         double sum = 0;
//         GetN(&n);
//         for (int i = 0; i < n; ++i) {
//             GetN(&num);
//             sum += num;
//         }
//         PutD(sum + 1);
//     }

//     if (rank == 3) {
//         int n;
//         double num;
//         double sum = 0;
//         GetN(&n);
//         GetN(&n);
//         for (int i = 0; i < n; ++i) {
//             GetD(&num);
//             sum += num;
//         }
//         PutD(sum);
//     }

//     if (rank == 4) {
//         int n;
//         double num;
//         double sum = 0;
//         GetN(&n);
//         for (int i = 0; i < n; ++i) {
//             GetD(&num);
//             sum += num;
//         }
//         PutD(sum);
//         PutD(sum);
//     }

//     if (rank == 5) {
//         int n;
//         double num;
//         double sum = 0;
//         GetN(&n);
//         for (int i = 0; i < n; ++i) {
//             GetD(&num);
//             sum += num;
//         }
//         PutD(sum);
//     }

//     if (rank == 6) {
//         int n;
//         double num;
//         double sum = 0;
//         GetN(&n);
//         for (int i = 0; i < n; ++i) {
//             GetD(&num);
//             sum += num;
//         }
//         PutD(sum);
//     }

//     if (rank == 7) {
//         int n;
//         double num;
//         double sum = 0;
//         GetN(&n);
//         for (int i = 0; i < n; ++i) {
//             GetD(&num);
//             sum += num;
//         }
//         PutD(sum);
//     }

    
//     MPI_Finalize();
// }