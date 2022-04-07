#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

struct ip_socket
{
    char ip_addr[16]; // xxx.xxx.xxx.xxx\0
    int port; // ports 0-65535\0
};

void modify_port(struct ip_socket *, struct ip_socket *);
void print_details(struct ip_socket *, struct ip_socket *);

int main()
{
    struct ip_socket sock1 = {.port =1066};
    struct ip_socket sock2 = {.port = 1066};
    char yesno;
    printf("Enter IP of first machine: ");
    scanf("%s", &sock1.ip_addr);
    printf("\nEnter IP of second machine: ");
    scanf("%s", &sock2.ip_addr);

    print_details(&sock1, &sock2);
    printf("\nModify port number for machines? (Y/N) ");
    scanf(" %c", &yesno);
    yesno=getchar();
    yesno=tolower(yesno);
    if(yesno == 'y')
    {
        modify_port(&sock1, &sock2);
        print_details(&sock1, &sock2);
    }

    return 0;
}

void print_details(struct ip_socket *s1, struct ip_socket *s2)
{
    printf("\nCurrent Details\n");
    printf("Machine 1 IP: %s\nMachine 1 Port: %d\n\nMachine 2 IP: %s\nMachine 2 Port: %d", s1->ip_addr, s1->port, s2->ip_addr, s2->port);
}

void modify_port(struct ip_socket *s1, struct ip_socket *s2)
{
    int portnew;
    printf("\nEnter a new port number for machine 1 (or 0 to keep current port): ");
    scanf("%d", &portnew);
    if(portnew != 0)
    {
        s1->port = portnew;
    }
    printf("\nEnter a new port number for machine 2 (or 0 to keep current port): ");
    scanf("%d", &portnew);
    if(portnew != 0)
    {
        s2->port = portnew;
    }
}