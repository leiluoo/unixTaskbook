#ifndef UDATA_H
#define UDATA_H

#include <string>
#include "colors.hpp"

const int MaxWidth = 80;
const std::string FileName = "$$pt4dat$$.dat";

const std::string NoInputMsg = "Data are not input.";
const std::string DemoRunMsg = "Demo running.";
const std::string AcquaintanceRunMsg = "Acquaintance running.";
const std::string NoOutputMsg = "Data are not output.";
const std::string NotAllOutputMsg = "Some required data are not output.";
const std::string TooManyOutputMsg = "An attempt to output superfluous data.";
const std::string WrongTypeOutputMsg = "Invalid type is used for an output data item.";
const std::string RightSolutionMsg = "Right solution.";
const std::string WrongSolutionMsg = "Wrong solution.";

//message from ut1.c
//const std::string NoInputMsg = "Data are not input.";
const std::string NotAllInputMsg = "Some required data are not input.";
const std::string TooManyInputMsg = "An attempt to input superfluous data.";
const std::string WrongTypeInputMsg = "Invalid type is used for an input data item.";

struct TData {
    char id;           // b, i, r, c, s
    double n;          // used for b, i, r
    std::string s;          // used for c, s
    int x, y, w, p, r;
};

struct TComment {
    std::string s;
    int x, y;
};

typedef TData TDataArray[201];
typedef TComment TCommentArray[206];

bool LoadData();
void CreateAddFiles();
void PrintTaskDemo();
bool CheckAllResults();
void PrintTask();
int  GetCursize();

#endif // UDATA_H
