#include "stdafx.h"

int main(int* argc, char** argv)
{   

#ifdef _DEBUG
    VLDSetReportOptions(VLD_OPT_REPORT_TO_DEBUGGER | VLD_OPT_UNICODE_REPORT, NULL);
#endif

	Game game(argc, argv);
    return 0;
}