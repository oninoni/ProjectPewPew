#include "stdafx.h"

int main(int* argc, char** argv)
{   
    VLDSetReportOptions(VLD_OPT_REPORT_TO_DEBUGGER | VLD_OPT_UNICODE_REPORT, NULL);

    Game game(argc, argv);
    return 0;
}

