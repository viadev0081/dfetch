#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/colors.h"
#include "lib/distros.h"
#include "lib/get_parameters.h"

int detect_distro(char *result, size_t result_size) {
    FILE *file = fopen("/etc/os-release", "r");
    if (!file) {
        perror("Ошибка при открытии /etc/os-release");
        return -1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Проверяем, начинается ли строка с "ID="
        if (strncmp(line, "ID=", 3) == 0) {
            char *id = line + 3; // Пропускаем "ID="

            // Удаляем символ переноса строки в конце
            id[strcspn(id, "\r\n")] = 0;

            // Удаляем кавычки, если они есть
            if (id[0] == '"') {
                id++; // Сдвигаем начало за первую кавычку
                char *end = strrchr(id, '"');
                if (end) *end = 0; // Обнуляем строку на последней кавычке
            }

            strncpy(result, id, result_size - 1);
            result[result_size - 1] = '\0';
            fclose(file);
            return 0;
        }
    }

    fclose(file);
    return -2;
}

int main() {
    char distro[64];
    int status = detect_distro(distro, sizeof(distro));

    if (status == -1) {
        exit(1);
    }
    else if (status == -2) {
        fprintf(stderr, "ID не найден в /etc/os-release\n");
        exit(1);
    }

    if (strcmp(distro, "linuxmint") == 0) {
        mint_fetch();
    }
    else if (strcmp(distro, "debian") == 0) {
        debian_fetch();
    }
    else if (strcmp(distro, "nixos") == 0) {
        nix_fetch();
    }
    else if (strcmp(distro, "artix") == 0) {
        artix_fetch();
    }
    else if (strcmp(distro, "android") == 0) {
        android_fetch();
    }
    else if (strcmp(distro, "arch") == 0) {
        arch_fetch();
    }
    else if (strcmp(distro, "endeavouros") == 0) {
        endeavour_fetch();
    }
    else if (strcmp(distro, "freebsd") == 0) {
        freebsd_fetch();
    }
    else if (strcmp(distro, "netbsd") == 0) {
        netbsd_fetch();
    }
    else if (strcmp(distro, "gentoo") == 0) {
        gentoo_fetch();
    }
    else if (strcmp(distro, "void") == 0) {
        void_fetch();
    }
    else if (strcmp(distro, "devuan") == 0) {
        devuan_fetch();
    }
    else {
        printf("Дистрибутив %s не поддерживается dfetch\n", distro);
    }

    return 0;
}
