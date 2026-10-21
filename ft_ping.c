#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>

void    help_page() {
    printf("Usage:\n");
    printf("  ft_ping [options] <destination>\n");
    printf("Options:\n");
    printf("  <destination>\t\tDNS name or IP address\n");
    printf("  -v\t\t\tverbose output\n");
    printf("  -?\t\t\thelp menu");
}

int     main(int ac, char **av) {
    int i = 0;
    // size_t verbose = 0;
    char *domain = NULL;
    char *options[] = {"-v", "-?"};
    
    if (ac < 2 || ac > 4)
        return 1;

    while (++i < ac) {
        if (!strcmp(options[1], av[i])) {
            help_page();
            return EXIT_SUCCESS;
        }
        if (!strcmp(options[0], av[i]))
            // verbose = 1;
        if (av[i][0] == '-' && strcmp(av[i], options[0]) && strcmp(av[i], options[1]))
            return(help_page(), EXIT_FAILURE);
        if (strcmp(options[0], av[i]) && strcmp(options[1], av[i])) {
            if (domain == NULL)
                domain = av[i];
            else
                return(help_page(), EXIT_FAILURE);
        } 
    }
    if (domain == NULL)
        return(help_page(), EXIT_FAILURE);

    return 0;
}