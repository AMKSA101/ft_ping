#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

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
    size_t verbose = 0;
    char *domain = NULL;
    char *options[] = {"-v", "-?"};
    
    if (ac < 2 || ac > 4)
        return (printf("ft_ping: usage error: Destination address required\n"), 2);
        
    while (++i < ac) {
        if (!strcmp(options[1], av[i])) {
            help_page();
            return EXIT_SUCCESS;
        }
        if (!strcmp(options[0], av[i]))
            verbose = 1;
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
        return (printf("ft_ping: usage error: Destination address required\n"), 2);

    struct addrinfo hints, *res = NULL;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    int status = getaddrinfo(domain, NULL, &hints, &res);
    if (status)
        return(fprintf(stderr, "ft_ping: %s\n", gai_strerror(status)), EXIT_FAILURE);
    
    struct sockaddr_in addr;
    memcpy(&addr, res->ai_addr, sizeof(addr));
    freeaddrinfo(res);
    char ip_buf[INET_ADDRSTRLEN];
    if (!inet_ntop(AF_INET, &addr.sin_addr, ip_buf, sizeof(ip_buf)))
        return(EXIT_FAILURE);
    printf("The domain is %s\tResolved to %s\n", domain, ip_buf);
    if (verbose)
        printf("verbose");
    return 0;
}