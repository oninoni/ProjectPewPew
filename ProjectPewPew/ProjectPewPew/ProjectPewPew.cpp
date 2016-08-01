#include "stdafx.h"

int main(int* argc, char** argv)
{   
    Game game(argc, argv);

    VLDSetReportOptions(VLD_OPT_REPORT_TO_DEBUGGER | VLD_OPT_UNICODE_REPORT, NULL);
    
    return 0;
}

