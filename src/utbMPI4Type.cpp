#include "tasklib.hpp"
#include "pt4utilities.hpp"

class utbMPI4Type : public TaskLib
{
private:
	std::string task_group;

public:
	utbMPI4Type();
	virtual ~utbMPI4Type() {}

	virtual void utb_set_theme(std::string theme) {
		pt4_set_theme(theme);
	}

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
	return new utbMPI4Type;
}

extern "C" void destroy(TaskLib *t)
{
	delete t;
}

utbMPI4Type::utbMPI4Type()
{
#if defined __linux__
	library_name = "libutbMPI4Type.so";
#elif defined __APPLE__
	library_name = "libutbMPI4Type.dylib";
#endif

	compiler = "mpicc";
	compile_argv = {compiler, "-Wall", "-w", "", "ut1mpi.c", "-o"};

	execute_argv = {};

	task_group = "MPI4Type";
	task_count = 22;
	total_test_count = 3;

	print_file = false;
	print_task_info = true;
}
