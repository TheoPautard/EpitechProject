#include "../include/PWGenerator.h"

void loadingBar(int nb_char)
{
    // 0 - black background,
    // A - Green Foreground
  
    // Initialize char for printing
    // loading bar
    char b = '*';
  
    printf("\n\n\t\t\t\t\t\t\t\t||===========================||\n");
    printf("\t\t\t\t\t\t\t\t||   \033[1;33mGenerating Password...\033[0m  ||\n");
    if (nb_char < 10)
        printf("\t\t\t\t\t\t\t\t||      \033[1;33mof %d characters\033[0m      ||\n", nb_char);
    if (nb_char >= 10)
        printf("\t\t\t\t\t\t\t\t||      \033[1;33mof %d characters\033[0m     ||\n", nb_char);
    printf("\t\t\t\t\t\t\t\t||                           ||\n");
    printf("\r");
    printf("\t\t\t\t\t\t\t\t|| ");
    // Print loading bar progress
    for (int i = 0; i < 25; i++) {
        printf("%c", b);
    }
    printf(" ||");
}

int pwgenerator(char **av)
{
    int nb_char = atoi(av[1]);
    char *password = malloc(sizeof(char) * nb_char + 1);

    srandom(time(NULL));
    loadingBar(nb_char);
    for (int i = 0; i < nb_char; i++)
        password[i] = 33 + rand() % (126 + 1 - 33);
    printf("\n\t\t\t\t\t\t\t\t||                           ||");
    printf("\n\t\t\t\t\t\t\t\t||");
    int i = 0;
    printf("\033[1;33mPassword\033[0m = %s", password);
    if (nb_char < 16) {
        i = 16 - nb_char;
        for (int j = 0; j != i; j++)
            printf(" ");
    }
    printf("||\n");
    printf("\t\t\t\t\t\t\t\t||===========================||\n\n");
    free(password);
    return (0);
}