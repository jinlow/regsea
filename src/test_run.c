#include <stdio.h>
#include "mxdata.h"

//int argc, char **argv
int main()
{
    Mxdata mat = init_Mxdata(10, 3, 0);
    print_Mxdata(mat);
    free_Mxdata(mat);
    return 0;
}
