#include <stdio.h>
#include <stdlib.h>
#include "distros.h"
#include "get_parameters.h"
#include "colors.h"

void endeavour_fetch() {
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

    printf("\n");
    printf(MAGENTA_COLOR "                      " RESET_COLOR MAGENTA_COLOR " User:   %s" RESET_COLOR "\n", username);
    printf(MAGENTA_COLOR "           /o.        " RESET_COLOR MAGENTA_COLOR "───────────────────" RESET_COLOR "\n");
    printf(MAGENTA_COLOR "         /sssso-      " RESET_COLOR MAGENTA_COLOR "󰌢 Host:  %s" RESET_COLOR "\n", hostname);
    printf(MAGENTA_COLOR "       /ossssssso:    " RESET_COLOR MAGENTA_COLOR " OS:    %s" RESET_COLOR "\n", osname);
    printf(MAGENTA_COLOR "     /ssssssssssso+   " RESET_COLOR MAGENTA_COLOR " Kernel:%s" RESET_COLOR "\n", kernel);
    printf(MAGENTA_COLOR "   /ssssssssssssssso+ " RESET_COLOR MAGENTA_COLOR " Shell: %s" RESET_COLOR "\n", shell);
    printf(MAGENTA_COLOR " //osssssssssssssso+- " RESET_COLOR MAGENTA_COLOR " DE/WM: %s" RESET_COLOR "\n", de_wm);
    printf(MAGENTA_COLOR "  `+++++++++++++++-`  " RESET_COLOR MAGENTA_COLOR " Init system:%s" RESET_COLOR "\n", init);
    printf(MAGENTA_COLOR "                      " RESET_COLOR MAGENTA_COLOR "" RESET_COLOR "\n");
    printf(MAGENTA_COLOR "      ENDEAVOUR OS    " RESET_COLOR RED_COLOR "█" GREEN_COLOR "█" YELLOW_COLOR "█" BLUE_COLOR "█" MAGENTA_COLOR "█" CYAN_COLOR "█" RESET_COLOR "\n");
    printf("\n");

    free(username);
    free(hostname);
    free(osname);
    free(kernel);
    free(shell);
    free(de_wm);
    free(init);
}
