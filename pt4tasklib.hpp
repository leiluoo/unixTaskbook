#ifndef PT4TASKLIB_HPP
#define PT4TASKLIB_HPP

#include "header.hpp"
#include "tasklib.hpp"

class pt4TaskLib : public TaskLib
{
protected:
	std::string task_group;

public:
	// Public real function
	// Implemented by tasklib itself
	pt4TaskLib() 
	{ 
		print_file = false;
	}

	// The virtual function (interface)
	// Implemented by each tasklib itself
	virtual void utb_print_task_info(int task_num, int language_option); 
//	virtual bool utb_print_file_info(); 
	virtual void utb_generate_task_test(int task_num, int test_num);
	virtual void utb_generate_task_control(int task_num);
	virtual void utb_print_extra_info(int task_num);
	virtual int utb_check_program(int test_num) const;
	virtual ~pt4TaskLib() {}

	// friend class
	friend class UnixTaskbook;
};

// the types of the class factories
//typedef TaskLib *create_t();
//typedef void destroy_t(TaskLib *);

#endif