#ifndef FUNC_H
#define FUNC_H

#include "libs.h"
#include "commands.h"
#include "../ahsh.h"

// Register commands here. Make sure they line up with the values in the str.h file!
int (*builtin_func[]) (char **) = {
	&sh_echo,
	&sh_help,
	&sh_exit,
	&sh_ver,
	&sh_crdir,
	&sh_crfile,
	&sh_clear,
	&sh_reboot,
	&sh_add,
	&sh_sub,
	&sh_mul,
	&sh_div,
	&sh_pcd,
	&sh_del,
	&sh_rename,
	&sh_list,
	&sh_cd,
	&sh_pfc,
	&sh_sex,
	&sh_write,
	&sh_clrfile,
	&sh_append
};

#endif