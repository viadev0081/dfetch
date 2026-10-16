#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./lib/get_parameters.h"
#include "./lib/colors.h"

char * run_command(const char * cmd) {
    char buffer[256];
    char * result = NULL;
    FILE * pipe = popen(cmd, "r");

    if (!pipe) {
        return strdup("Error");
    }

    if (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        buffer[strcspn(buffer, "\r\n")] = 0;
        result = strdup(buffer);
    }
    else {
        result = strdup("Unknown");
    }

    pclose(pipe);
    return result;
}

char * get_user_name() {
    return run_command("whoami");
}

char * get_host_name() {
    return run_command("uname -n");
}

char * get_operating_system_name() {
    return run_command("uname -o");
}

char * get_kernel() {
    return run_command("uname -sr");
}

char * get_shell() {
    char * shell_env = getenv("SHELL");
    if (shell_env && strlen(shell_env) > 0) {
        return strdup(shell_env);
    }

    const char * paths[][2] = {
        // --- Linux paths for shell --- //
        { "/usr/bin/fish", "fish"},
        { "/usr/bin/bash", "bash"},
        { "/usr/bin/zsh", "zsh"},
        { "/usr/bin/sh",   "sh"},

        // --- FreeBSD paths for shell --- //
        { "/usr/local/bin/fish", "fish" },
        { "/usr/local/bin/bash", "bash" },
        { "/usr/local/bin/zsh",  "zsh" },
        { "/usr/local/bin/sh",   "sh" },

        // --- NixOS paths for shell --- //
        { "/run/current-system/sw/bin/fish", "fish"},
        { "/run/current-system/sw/bin/bash", "bash"},
        { "/run/current-system/sw/bin/sh",   "sh"}
    };

    int num_paths = sizeof(paths) / sizeof(paths[0]);
    for (int i = 0; i < num_paths; i++) {
        if (access(paths[i][0], F_OK) == 0) {
            return strdup(paths[i][1]);
        }
    }

    return strdup("Unknown");
}

char * get_desktop_environment() {
    const char * vars[] = {
        "XDG_CURRENT_DESKTOP",
        "DESKTOP_SESSION",
        "GDMSESSION"

    };

    int num_vars = sizeof(vars) / sizeof(vars[0]);

    for (int i = 0; i < num_vars; i++) {
        char * val = getenv(vars[i]);
        if (val && strlen(val) > 0) {
            return strdup(val);
        }
    }

    return strdup("Unknown");
}

char * refine_init() {
    if (access("/run/openrc", F_OK) == 0) {
        return strdup("OpenRC");
    }

    if (access("/var/service", F_OK) == 0) {
        return strdup("Runit");
    }

    if (access("/etc/init.d", F_OK) == 0) {
        return strdup("SysVinit");
    }

    return strdup("init (Unknown)");
}

char * get_init() {
    char * init = run_command("ps -p 1 -o comm=");

    if (strcmp(init, "init") == 0) {
        char * refined = refine_init();
        free(init);
        return refined;
    }

    return init;
}
