#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <mpi.h>


void ShowB(bool b);
void ShowN(int n);
void ShowD(double d);
void ShowC(char c);
void ShowS(const char *s);

void ShowCmt(const char *cmt);
void ShowWCmt(const wchar_t *cmt);
void ShowLine(void);

void PutB(bool a);
void PutN(int a);
void PutD(double a);
void PutC(char a);
void PutS(const char *a);

void GetB(bool *a);
void GetN(int *a);
void GetD(double *a);
void GetC(char *a);
void GetS(char *a);

void SetPrecision(int n);
void SetWidth(int n);
void SetW(int n);
