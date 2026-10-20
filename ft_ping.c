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
    exit(0);
}

int     main(int ac, char **av) {
    int i = 0;
    char *options[] = {"-v", "-?"};
    
    if (ac < 2 || ac > 4)
        return 1;

    while (i < ac) {
        if (!strcmp(options[1], av[i++]))
            help_page();
        
    }
    
    return 0;
}