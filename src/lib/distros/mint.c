#include <stdio.h>
#include <stdlib.h>
#include "distros.h"
#include "get_parameters.h"
#include "colors.h"

void mint_fetch() {
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

    printf(GREEN_COLOR " " RESET_COLOR "\n");
    printf(GREEN_COLOR " ___________   " RESET_COLOR GREEN_COLOR " User:%s" RESET_COLOR "\n", username);
    printf(GREEN_COLOR "|_          \\ " RESET_COLOR MAGENTA_COLOR "───────────────────" RESET_COLOR "\n");
    printf(GREEN_COLOR "  | | _____ | " RESET_COLOR GREEN_COLOR "󰌢 Host:%s" RESET_COLOR "\n", hostname);
    printf(GREEN_COLOR "  | | | | | | " RESET_COLOR GREEN_COLOR " OS:%s" RESET_COLOR "\n", osname);
    printf(GREEN_COLOR "  | | | | | | " RESET_COLOR GREEN_COLOR " Kernel:%s" RESET_COLOR "\n", kernel);
    printf(GREEN_COLOR "  | \\_____/ | " RESET_COLOR GREEN_COLOR " Shell:%s" RESET_COLOR "\n", shell);
    printf(GREEN_COLOR "  \\_________/ " RESET_COLOR GREEN_COLOR " DE/WM:%s" RESET_COLOR "\n", de_wm);
    printf(GREEN_COLOR "              " RESET_COLOR GREEN_COLOR " Init system:%s" RESET_COLOR "\n", init);
    printf(GREEN_COLOR "    MINT       " RESET_COLOR GREEN_COLOR "" RESET_COLOR "\n");
    printf(GREEN_COLOR "              " RESET_COLOR RED_COLOR "█" GREEN_COLOR "█" YELLOW_COLOR "█" BLUE_COLOR "█" MAGENTA_COLOR "█" CYAN_COLOR "█" RESET_COLOR "\n");
    printf("\n");

    free(username);
    free(hostname);
    free(osname);
    free(kernel);
    free(shell);
    free(de_wm);
    free(init);
}
