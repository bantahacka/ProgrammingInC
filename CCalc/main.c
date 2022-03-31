#include "header_includes.h"

int main(int argc, char *argv[])
{
    int exitflag = 0;
    char option[OPTMAXLEN];
    int opt_num;
    float ans;
    float num1;
    float num2;
    float mem;
    if(argc < 2)
    {
        printhelp();
        return 1;
    }
    if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "--start") != 0)
    {
        printhelp();
        return 1;
    }
    else
    {
        while(exitflag == 0)
        {
            printmenu();
            while(opt_num == 0)
            {
                fgets(option, OPTMAXLEN, stdin);
                opt_num = atoi(option);
            }

            printf("%d", opt_num);
            /*while(option < 1 || option > 12)
            {
                scanf("%d", &option);
            }*/

            switch(opt_num)
            {
                case 1:
                    num1 = enterfirst();
                    num2 = entersecond();
                    addition(num1, num2, &ans);
                    printf("\n%.2f + %.2f = %.2f\n", num1, num2, ans);
                    break;
                case 2:
                    num1 = enterfirst();
                    num2 = entersecond();
                    subtraction(num1, num2, &ans);
                    printf("\n%.2f - %.2f = %.2f\n", num1, num2, ans);
                    break;
                case 3:
                    num1 = enterfirst();
                    num2 = entersecond();
                    multiplier(num1, num2, &ans);
                    printf("\n%.2f x %.2f = %.2f\n", num1, num2, ans);
                    break;
                case 4:
                    num1 = enterfirst();
                    num2 = entersecond();
                    divider(num1, num2, &ans);
                    printf("\n%.2f \u00F7 %.2f = %.2f\n", num1, num2, ans);
                    break;
                case 5:
                    num1 = enterfirst();
                    num2 = entersecond();
                    pct(num1, num2, &ans);
                    printf("%.2f/%.2f as a percentage is %.2f%%\n", num1, num2, ans);
                    break;
                case 6:
                    num1 = enterfirst();
                    num2 = enterpwr();
                    topower(num1, num2, &ans);
                    printf("%.2f ^ %.2f = %.2f\n", num1, num2, ans);
                    break;
                case 7:
                    num1 = entersingle();
                    sqroot(num1, &ans);
                    printf("The square root of %.2f is %.2f\n", num1, ans);
                    break;
                case 8:
                    num1 = entersingle();
                    curt(num1, &ans);
                    printf("The cube root of %.2f is %.2f\n", num1, ans);
                    break;
                case 9:
                    add_to_mem(&ans, &mem);
                    printf("\n%.2f added to memory.\n", ans);
                    break;
                case 10:
                    ret_from_mem(&ans, &mem);
                    printf("\nThe number in memory is: %.2f\n", ans);
                    break;
                case 11:
                    mem_clear(&mem);
                    printf("\nMemory cleared.\n");
                    break;
                case 12:
                    exitflag = 1;
                    break;
                default:
                    printf("\nInvalid option.\n");
                    //continue;
            }
            if(opt_num != 12)
            {
                opt_num = 0;
                continue;
            }
            else
            {
                break;
            }
        }
    }
    return 0;
}
