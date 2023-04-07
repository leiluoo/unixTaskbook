#include <string>
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <dlfcn.h>
#include <cstdlib>

#include "pt4utilities.hpp"
#include "udata.h"
#include "uprint.h"

void *FLibHandle = nullptr;

TInitGroup InitGroup_ = nullptr;
TInitTask InitTask_ = nullptr;

std::string dylib_name = "";

void free_lib()
{
    if (FLibHandle != nullptr)
    {
        dlclose(FLibHandle);
        FLibHandle = 0;
    }
}

bool load_lib()
{
    bool result = false;
    free_lib();
#if defined __linux__
	dylib_name += ".so";
#elif defined __APPLE__
	dylib_name += ".dylib";
#endif
    FLibHandle = dlopen(dylib_name.c_str(), RTLD_LAZY);
    if (FLibHandle == nullptr)
    {
        return false;
    }
    InitGroup_ = (TInitGroup)dlsym(FLibHandle, "initgroup");
    if (InitGroup_ == nullptr)
    {
        free_lib();
        return false;
    }
    InitTask_ = (TInitTask)dlsym(FLibHandle, "inittask");
    if (InitTask_ == nullptr)
    {
        free_lib();
        return false;
    }
    return true;
}

void init_group(const std::string &name)
{
    if (FLibHandle == 0)
        return;
    InitGroup_(const_cast<char *>(name.c_str()));
}

void init_task(int num, int test)
{
    if (FLibHandle == 0)
        return;
    InitTask_(num, test);
}

void check_dylib(std::string task_group)
{
    if (task_group.find("MPI") != std::string::npos) 
        dylib_name = "libmpipt4_en";
    else 
        dylib_name = "libpt4_en";
}

void pt4_print_task_info(std::string task_group, int task_num, int language_option)
{
// shows task info (see InitPrg)
	//std::cout<< "<<<Task formulation output>>>" << std::endl;
    check_dylib(task_group);
    if (!load_lib())
    {
        return;
    }
    init_group(task_group);
    init_task(task_num, 0);
    if (LoadData())
    {
        PrintTaskDemo();
    }
}

void pt4_generate_task_test(std::string task_group, int task_num, int test_num)
{
// creates all necessary files for selected task (see InitPrg)
	//std::cout<< "<<<Creation of required files>>>" << std::endl;
    check_dylib(task_group);
    if (!load_lib())
        return;
    init_group(task_group);
    init_task(task_num, test_num);
    
    CreateAddFiles();
}

void pt4_print_extra_info(std::string task_group, int task_num)
{
// shows results (see CheckPrg)
	//std::cout<< "<<<Task results output>>>" << std::endl;
    PrintTask();
}

int pt4_check_program(std::string task_group, int test_num)
{
    bool result = false;
	//std::cout<< "<<<Checking the results>>>" << std::endl;    
    result = CheckAllResults();
	return result ? 0 : 1;
// checks results (see CheckPrg)
}

int pt4_mpi_get_size()
{
    return GetCursize();
}
