#include <stdio.h>
#include <stdlib.h>
#include "distros.h"
#include "get_parameters.h"
#include "colors.h"

void nix_fetch() {
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

    printf(CYAN_COLOR "" RESET_COLOR "\n");
    printf(CYAN_COLOR "   \\\\  \\\\ //   " RESET_COLOR CYAN_COLOR " User:%s" RESET_COLOR "\n", username);
    printf(CYAN_COLOR "  ==\\\\__\\\\/ // " RESET_COLOR MAGENTA_COLOR "───────────────────" RESET_COLOR "\n");
    printf(CYAN_COLOR "    //   \\\\//  " RESET_COLOR CYAN_COLOR "󰌢 Host:%s" RESET_COLOR "\n", hostname);
    printf(CYAN_COLOR " ==//     //== " RESET_COLOR CYAN_COLOR " OS:%s" RESET_COLOR "\n", osname);
    printf(CYAN_COLOR "  //\\\\___//    " RESET_COLOR CYAN_COLOR " Kernel:%s" RESET_COLOR "\n", kernel);
    printf(CYAN_COLOR " // /\\\\  \\\\==  " RESET_COLOR CYAN_COLOR " Shell:%s" RESET_COLOR "\n", shell);
    printf(CYAN_COLOR "   // \\\\  \\\\   " RESET_COLOR CYAN_COLOR " DE/WM:%s" RESET_COLOR "\n", de_wm);
    printf(CYAN_COLOR "               " RESET_COLOR CYAN_COLOR " Init system: %s" RESET_COLOR "\n", init);
    printf(CYAN_COLOR "     NIXOS        " RESET_COLOR CYAN_COLOR "" RESET_COLOR "\n");
    printf(CYAN_COLOR "               " RESET_COLOR RED_COLOR "█%s█%s█%s█%s█%s" RESET_COLOR "\n",
           GREEN_COLOR, YELLOW_COLOR, BLUE_COLOR, MAGENTA_COLOR, CYAN_COLOR);
    printf("\n");

    free(username);
    free(hostname);
    free(osname);
    free(kernel);
    free(shell);
    free(de_wm);
    free(init);
}
