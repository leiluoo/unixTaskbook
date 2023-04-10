#include <stdbool.h>
#include <wchar.h>

void ShowB(bool b);
void ShowN(int n);
void ShowD(double d);
void ShowC(char c);
void ShowS(const char *s);

void Show(const char *cmt);
void ShowW(const wchar_t *cmt);

void ShowLineB(bool b);
void ShowLineN(int n);
void ShowLineD(double d);
void ShowLineC(char c);
void ShowLineS(const char *s);

void ShowLine(const char *cmt);
void ShowLineW(const wchar_t *cmt);

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
