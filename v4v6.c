
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define TEST_PORT 10051

#define xstr(s) str(s)
#define str(x) #x

int main (int argc, char **argv)
{
    int v6server;
    int v4client;
    int rc;

    struct sockaddr_in6 s6addr = {
        .sin6_family = AF_INET6,
        .sin6_flowinfo = 0,
        .sin6_port = htons(TEST_PORT),
        .sin6_addr = in6addr_any
    };

    struct sockaddr_in c4addr = {
        .sin_family = AF_INET,
        .sin_port = htons(TEST_PORT),
        .sin_addr = inet_addr("The ip address that needs see something on this port")
    };

    // Open an IPv6 listener
    v6server = socket(AF_INET6, SOCK_STREAM, 0);
    if (v6server < 0) perror("socket()");

    rc = bind(v6server, (struct sockaddr *)&s6addr, sizeof(s6addr));
    if (rc != 0) perror("bind()");

    rc = listen(v6server, 0);
    if (rc != 0) perror("listen()");

    // Connect to the listener with an IPv4 socket
    v4client = socket(AF_INET, SOCK_STREAM, 0);
    if (v4client < 0) perror("socket()");

    rc = connect(v4client, (struct sockaddr *)&c4addr, sizeof(c4addr));
    if (rc != 0) perror("connect()");

    // inspect open sockets
    system("netstat -tan | grep " xstr(TEST_PORT));

    close(v4client);
    close(v6server);
}
