// #include <stdlib.h>
// #include <stdio.h>
// #include <math.h>
// #include "ut1.h"


// // This is an example of a simple console program
// int main(void)
// {
//    int a;
//    double x;
//    GetD(&x);
//    ShowCmt("x = ");
//    ShowD(x);
//    PutN(a % 10);
//    PutN(a / 10 % 10);
//    GetN(&a);


//     //system("pause");
//     return 0;
// }

#include "ut1.h"
// #include <mpi.h>

int main(int argc, char** argv) {
    // 初始化MPI环境
    MPI_Init(NULL, NULL);
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	double x;
	if (rank == 0) {
		GetD(&x);
		PutD(-x);
		ShowCmt("-X=");
        ShowD(-x);
	}
	else {
		PutN(rank);
		ShowCmt("rank=");
        ShowN(rank);
	}
    // 结束MPI环境
    MPI_Finalize();
}
