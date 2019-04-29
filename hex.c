#include "hex.h"

int char2int( char temp )
{

	if (47 < temp && temp < 58) 		// char 0-9
		return temp - 0x30;
	else if (64 < temp && temp < 91)	// char A-Z
		return temp - 0x37;
	else if (96 < temp && temp < 123)	// char a-z
		return temp - 0x57;
	else
		return -1;
}

int str2int( char *temp, char nu )
{
	int result = 0;

	if (strlen( temp ) > 0) {
		for (int i = nu - 1; i >= 0; i--) {
			if ( '0' == temp[i]) 
				continue;
			else
				result += char2int( temp[i] ) * (int)pow( 16.0, nu - i - 1);	
		}
		
		return result;
	}

	return -1;
}
