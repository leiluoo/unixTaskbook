#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <stdbool.h>
#include <mpi.h>

#define NoInputMsg "Data are not input.\n"
#define NotAllInputMsg "Some required data are not input.\n"
#define TooManyInputMsg "An attempt to input superfluous data.\n"
#define WrongTypeInputMsg "Invalid type is used for an input data item.\n"

int prec = 2;
int width = 0;
int width1 = -1;

struct TData
{
  char id;
  double r;
  char s[200];
} idata[201];

char InfoS[350], indat[13], outdat[13], errdat[13], showdat[13];

int psize = -1, prank = -1, useddata = 0, nidata = 0, idatacount = 0;

void error_(const char *msg)
{
  FILE *f = fopen(errdat, "w");
  fputs(msg, f);
  fclose(f);
}

// void ShowC(char c);
// void ShowD(double c);
// void ShowCmt(const char *cmt);

void init_(void)
{
  psize = 0;
  MPI_Comm_rank(MPI_COMM_WORLD, &prank);
  FILE *f = fopen("ut1inf.dat", "r");
  if (f == 0)
    return;
  int ver;
  fscanf(f, "%d", &ver);
  if (ver == 11)
  {
    fscanf(f, "%d", &psize);
    fscanf(f, "%d", &useddata);
    sprintf(indat, "ut1in%d.dat", prank);
    sprintf(outdat, "ut1out%d.dat", prank);
    sprintf(errdat, "ut1err%d.dat", prank);
    sprintf(showdat, "ut1sh%d.dat", prank);
    fclose(f);
    remove(outdat);
    remove(errdat);
    remove(showdat);
    f = fopen(indat, "r");
    if (f != NULL)
    {
      char id[200];
      while (fgets(id, 10, f)) // reading all input data
                               // and determing data size
      {
        idata[nidata].id = id[0];
        fgets(id, 200, f);
        switch (idata[nidata].id)
        {
        case 'b':
        case 'i':
          idata[nidata].r = atoi(id);
          break;
        case 'r':
          idata[nidata].r = atof(id);
          break;
        case 'c':
          idata[nidata].s[0] = id[0];
          break;
        case 's':
          strcpy(idata[nidata].s, id);
          break;
        }
        ++nidata;
      }
      error_(NoInputMsg);
      if (useddata == 0 || prank > 0) // for slave processes,
                                      // we do not take useddata into account;
                                      // all input data are required to input
        useddata = nidata;
      idatacount = 0;
    }
  }
  if (f != NULL)
    fclose(f);
}

bool addchar = false;

void show_(char *s)
{
  if (psize == -1)
    init_();
  if (psize == 0)
  {
    if (addchar)
      printf("%s", " ");
    printf("%s", s);
  }
  else
  {
    FILE *f = fopen(showdat, "a");
    if (addchar)
      fprintf(f, "%s", " ");
    fprintf(f, "%s", s);
    fclose(f);
  }
  addchar = true;
}

void ptruutf8_(const char *s1, char *s2)
{
  strcpy(s2, s1); // STUB; not implemented yet
                  // (need only for Russian texts)
}

void ptutf8_(const char *s1, char *s2)
{
  strcpy(s2, s1); // STUB; not implemented yet
                  // (need only for Russian texts)
}

void ShowB(bool b)
{
  int w = width1 == -1 ? width : width1;
  if (b)
    sprintf(InfoS, "%*s", -w, "true ");
  else
    sprintf(InfoS, "%*s", -w, "false");
  show_(InfoS);
  width1 = -1;
}

void ShowC(char c)
{
  int w = width1 == -1 ? width : width1;
  char s[] = {'\'', c, '\'', '\0'};
  char *s2 = (char *)malloc(w <= 3 ? 4 : (w + 1));
  if (s2 != 0)
  {
    sprintf(s2, "%*s", -w, s);
    ptruutf8_(s2, InfoS);
    show_(InfoS);
    free(s2);
  }
  width1 = -1;
}

void ShowN(int n)
{
  int w = width1 == -1 ? width : width1;
  sprintf(InfoS, "%*d", w, n);
  show_(InfoS);
  width1 = -1;
}

void ShowD(double d)
{
  int w = width1 == -1 ? width : width1;
  if (prec > 0)
    sprintf(InfoS, "%*.*f", w, prec, d);
  else
    sprintf(InfoS, "%*.*e", w, prec == 0 ? 6 : -prec, d);
  show_(InfoS);
  width1 = -1;
}

void ShowS(const char *s)
{
  int w = width1 == -1 ? width : width1;
  int n = strlen(s) + 2;
  char *s3 = (char *)malloc(n + 1);
  if (s3 != 0)
  {
    sprintf(s3, "\"%s\"", s);
    if (n < w)
      n = w;
    char *s2 = (char *)malloc(n + 1);
    if (s2 != 0)
    {
      sprintf(s2, "%*s", -w, s3);
      char *s1 = (char *)malloc(3 * n + 1);
      if (s1 != 0)
      {
        ptruutf8_(s2, s1);
        show_(s1);
        free(s1);
      }
      free(s2);
    }
    free(s3);
  }
  width1 = -1;
}

void Show(const char *cmt)
{
  int n = strlen(cmt);
  char *s2 = (char *)malloc(n + 1);
  if (s2 == 0)
    return;
  strcpy(s2, cmt);
  for (int i = n - 1; i >= 0; --i)
    if (s2[i] == ' ')
      n = i;
    else
      break;
  s2[n] = '\0';
  if (n > 0) // empty comments are not printed
  {
    char *s1 = (char *)malloc(3 * n + 1);
    if (s1 != 0)
    {
      ptruutf8_(s2, s1);
      show_(s1);
      free(s1);
    }
  }
  free(s2);
}

void ShowW(const wchar_t *cmt)
{
  int n = wcslen(cmt);
  wchar_t *s2 = (wchar_t *)malloc((n + 1) * 2);
  if (s2 == 0)
    return;
  wcscpy(s2, cmt);
  for (int i = n - 1; i >= 0; --i)
    if (s2[i] == L' ')
      n = i;
    else
      break;
  s2[n] = L'\0';
  if (n > 0) // empty comments are not printed
  {
    char *s1 = (char *)malloc(4 * n + 1);
    if (s1 != 0)
    {
      ptutf8_((char *)s2, s1);
      show_(s1);
      free(s1);
    }
  }
  free(s2);
}

void showline_(void)
{
  addchar = false;
  show_("\n");
  addchar = false;
}

void ShowLineB(bool b)
{
  ShowB(b);
  showline_();
}

void ShowLineN(int n)
{
  ShowN(n);
  showline_();
}

void ShowLineD(double d)
{
  ShowD(d);
  showline_();
}

void ShowLineC(char c)
{
  ShowC(c);
  showline_();
}

void ShowLineS(const char *s)
{
  ShowS(s);
  showline_();
}

void ShowLine(const char *cmt)
{
  Show(cmt);
  showline_();
}

void ShowLineW(const wchar_t *cmt)
{
  ShowW(cmt);
  showline_();
}

void put_(char id, double n, char c, const char *s)
{
  if (psize == -1)
    init_();
  if (psize == 0)
  {
    switch (id)
    {
    case 'b':
      ShowB((int)n);
      break;
    case 'i':
      ShowN((int)n);
      break;
    case 'r':
      ShowD(n);
      break;
    case 'c':
      ShowC(c);
      break;
    case 's':
      ShowS(s);
      break;
    }
  }
  else
  {
    FILE *f = fopen(outdat, "a");
    fprintf(f, "%c\n", id);
    switch (id)
    {
    case 'b':
      fprintf(f, "%d\n", (int)n);
      break;
    case 'i':
      fprintf(f, "%d\n", (int)n);
      break;
    case 'r':
      fprintf(f, "%0.14e\n", n);
      break;
    case 'c':
      fprintf(f, "%c\n", c);
      break;
    case 's':
      fprintf(f, "%s\n", s);
      break;
    }
    fclose(f);
  }
}

void PutB(bool a)
{
  put_('b', (int)a, ' ', 0);
}

void PutN(int a)
{
  put_('i', a, ' ', 0);
}

void PutD(double a)
{
  put_('r', a, ' ', 0);
}

void PutC(char a)
{
  put_('c', 0, a, 0);
}

void PutS(const char *a)
{
  put_('s', 0, ' ', a);
}

void get_(char id, double *n, char *c, char *s)
{
  if (psize == -1)
    init_();
  if (psize == 0)
  {
    char sbuf[201];
    switch (id)
    {
    case 'b':
      show_("(0|1): ");
      scanf("%200s", sbuf);
      *n = (atoi(sbuf) == 0) ? 0 : 1;
      break;
    case 'i':
      show_("(int): ");
      scanf("%200s", sbuf);
      *n = atoi(sbuf);
      break;
    case 'r':
      show_("(dbl): ");
      scanf("%200s", sbuf);
      *n = atof(sbuf);
      break;
    case 'c':
      show_("(chr): ");
      scanf("%200s", sbuf);
      *c = sbuf[0];
      break;
    case 's':
      show_("(str): ");
      scanf("%200s", sbuf);
      strcpy(s, sbuf);
      break;
    }
    addchar = false;
  }
  else
  {
    if (idatacount == nidata)
    {
      error_(TooManyInputMsg);
      // exit(1);
      return;
    }
    if (id != idata[idatacount].id)
    {
      error_(WrongTypeInputMsg);
      // exit(1);
      return;
    }
    switch (id)
    {
    case 'b':
      *n = (int)idata[idatacount].r;
      break;
    case 'i':
      *n = (int)idata[idatacount].r;
      break;
    case 'r':
      *n = idata[idatacount].r;
      break;
    case 'c':
      *c = idata[idatacount].s[0];
      break;
    case 's':
      strcpy(s, idata[idatacount].s);
      break;
    }
    ++idatacount;
    if (idatacount < useddata)
      error_(NotAllInputMsg);
    else if (idatacount >= useddata)
      remove(errdat);
  }
}

void GetB(bool *a)
{
  double r = 0;
  char c = '\0';
  char s[201] = {'\0'};
  get_('b', &r, &c, s);
  *a = ((int)r == 1);
}

void GetN(int *a)
{
  double r = 0;
  char c = '\0';
  char s[201] = {'\0'};
  get_('i', &r, &c, s);
  *a = (int)r;
}

void GetD(double *a)
{
  double r = 0;
  char c = '\0';
  char s[201] = {'\0'};
  get_('r', &r, &c, s);
  *a = r;
}

void GetC(char *a)
{
  double r = 0;
  char c = '\0';
  char s[201] = {'\0'};
  get_('c', &r, &c, s);
  *a = c;
}

void GetS(char *a)
{
  double r = 0;
  char c = '\0';
  char s[201] = {'\0'};
  get_('s', &r, &c, s);
  strcpy(a, s);
}

void SetPrecision(int n)
{
  if (abs(n) <= 16)
    prec = n;
}

void SetWidth(int n)
{
  if (n >= 0 && n <= 100)
    width = n;
}

void SetW(int n)
{
  if (n >= 0 && n <= 100)
    width1 = n;
}
