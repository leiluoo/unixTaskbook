#include "tasklib.hpp"
#include "pt4utilities.hpp"

class utbMPI1Proc : public TaskLib
{
private:
	std::string task_group;

public:
	utbMPI1Proc();
	virtual ~utbMPI1Proc() {}

	virtual void utb_print_task_info(int task_num, int language_option)
	{
		pt4_print_task_info(task_group, task_num, language_option);
	}

	virtual void utb_generate_task_test(int task_num, int test_num)
	{
		pt4_generate_task_test(task_group, task_num, test_num);
		execute_argv = {"mpiexec", "-np", std::to_string(pt4_mpi_get_size())};
	}

	virtual void utb_generate_task_control(int task_num) {}

	virtual void utb_print_extra_info(int task_num)
	{
		pt4_print_extra_info(task_group, task_num);
	}

	virtual int utb_check_program(int test_num) const
	{
		return pt4_check_program(task_group, test_num);
	}

	// friend class
	friend class UnixTaskbook;
};

extern "C" TaskLib *create()
{
	return new utbMPI1Proc;
}

extern "C" void destroy(TaskLib *t)
{
	delete t;
}

utbMPI1Proc::utbMPI1Proc()
{
#if defined __linux__
	library_name = "libutbMPI1Proc.so";
#elif defined __APPLE__
	library_name = "libutbMPI1Proc.dylib";
#endif
	compiler = "mpicc";
	compile_argv = {compiler, "-Wall", "-w", "", "ut1mpi.c", "-o"};

	execute_argv = {};

	task_group = "MPI1Proc";
	task_count = 10;
	total_test_count = 3;

	print_file = false;
	print_task_info = true;
}
