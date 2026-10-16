#include <stdio.h>
#include <stdlib.h>
#include "distros.h"
#include "get_parameters.h"
#include "colors.h"

void freebsd_fetch() {
    char * username = get_user_name();
    char * hostname = get_host_name();
    char * osname   = get_operating_system_name();
    char * kernel   = get_kernel();
    char * shell    = get_shell();
    char * de_wm    = get_desktop_environment();
    char * init     = get_init();

    if (!username || 
        !hostname || 
        !osname || 
        !kernel || 
        !shell || 
        !de_wm || 
        !init
    ) {
        fprintf(stderr, "Ошибка: не удалось получить системные параметры\n");

        free(username); 
        free(hostname); 
        free(osname);
        free(kernel); 
        free(shell); 
        free(de_wm); 
        free(init);
        return;
    }

    printf(RED_COLOR "                        " RESET_COLOR "\n");
    printf(RED_COLOR "  /\\,-'''''-,/\\   " RESET_COLOR RED_COLOR " User:  %s" RESET_COLOR "\n", username);
    printf(RED_COLOR "  \\_)       (_/  " RESET_COLOR MAGENTA_COLOR "───────────────────" RESET_COLOR "\n");
    printf(RED_COLOR "  |           |   " RESET_COLOR RED_COLOR "󰌢 Host:  %s" RESET_COLOR "\n", hostname);
    printf(RED_COLOR "  |           |   " RESET_COLOR RED_COLOR "󰣠 OS:    %s" RESET_COLOR "\n", osname);
    printf(RED_COLOR "   ;         ;    " RESET_COLOR RED_COLOR " Kernel: %s" RESET_COLOR "\n", kernel);
    printf(RED_COLOR "    '-_____-'     " RESET_COLOR RED_COLOR " Shell: %s" RESET_COLOR "\n", shell);
    printf(RED_COLOR "                  " RESET_COLOR RED_COLOR " DE/WM: %s" RESET_COLOR "\n", de_wm);
    printf(RED_COLOR "     FreeBSD      " RESET_COLOR RED_COLOR " Init system: %s" RESET_COLOR "\n", init);
    printf(RED_COLOR "                  " RESET_COLOR RED_COLOR "" RESET_COLOR "\n");
    printf(RED_COLOR "                  " RESET_COLOR RED_COLOR "█"
    GREEN_COLOR "█" YELLOW_COLOR "█"
    BLUE_COLOR "█" MAGENTA_COLOR "█" CYAN_COLOR "█" RESET_COLOR "\n");
    printf("\n");

    free(username);
    free(hostname);
    free(osname);
    free(kernel);
    free(shell);
    free(de_wm);
    free(init);
}
