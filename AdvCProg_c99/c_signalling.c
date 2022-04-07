#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

#ifdef __unix__
#include <unistd.h>
#elif defined _WIN32
#include <windows.h>
#endif // __ unix __

#define sleep(x) Sleep(1000 * (x))

void my_signal_handler(int);

int main()
{
    // Registering/binding custom signal handler function to CTRL-C
    signal(SIGINT, my_signal_handler);
    while(1)
    {
        printf("Doing something...\n");
        // Pause 2 seconds
        sleep(2);
    }
    return 0;
}

void my_signal_handler(int sig_num)
{
    printf("Intercepted signal %d.\n", sig_num);
    if(sig_num == 2)
    {
        exit(sig_num);
    }

}