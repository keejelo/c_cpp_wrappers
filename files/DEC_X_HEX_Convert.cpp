//---------------------------------------------------------------------------------------------
// ** DEC_X_HEX_Convert.cpp
//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------
// ** Include files
//---------------------------------------------------------------------------------------------
#include "DEC_X_HEX_Convert.h"
#include <string>
//---------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------
// ** Decimal to HEX
//---------------------------------------------------------------------------------------------
std::string dec2hex(int num)
{
	char hex[100];
	sprintf_s(hex, "%x", num);
    return hex;
};
//---------------------------------------------------------------------------------------------
// ** END: Decimal to HEX
//---------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------
// ** HEX to Decimal
//---------------------------------------------------------------------------------------------
int hex2dec(const char *hex)
{
	unsigned int n;
	if (sscanf_s(hex, "%x", &n) == 1)
    {
        return n;
    }
    else
	{
		puts("Error converting from hex to decimal");
		return NULL;
	}
};
//---------------------------------------------------------------------------------------------
// ** END: HEX to Decimal
//---------------------------------------------------------------------------------------------
