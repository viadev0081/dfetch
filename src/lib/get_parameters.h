#ifndef GET_PARAMETERS_H
#define GET_PARAMETERS_H

char * run_command(const char * cmd);
char * get_user_name();
char * get_host_name();
char * get_operating_system_name();
char * get_kernel();
char * get_shell();
char * get_desktop_environment();
char * refine_init();
char * get_init();

#endif
