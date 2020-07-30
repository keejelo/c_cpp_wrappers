//---------------------------------------------------------------------------------------------
// ** FindBytePattern.cpp
//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------
// ** Include files
//---------------------------------------------------------------------------------------------
#include "FindBytePattern.h"
#include <string>
//---------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------
// ** Search for byte pattern inside a bigger byte array (loaded from a file into a buffer)
//---------------------------------------------------------------------------------------------
//    Returns the offset starting position where the pattern is found.
//    If pattern is not found it returns: std::string::npos
//    which is the size of an "unsigned int" or "size_t", in other words "end of file".
//
//    Should works for files up to 4GB  (size of "unsigned int" in Microsoft C++ compilers)
//
//    Tip: to get "patternSize" you can do: int patternSize = sizeof(pattern) / sizeof(pattern[0]);
//         And then supply it to the function before calling it.
//         We cannot do it in the function because we lose its value when passing it ..
//         Same goes for "fileSize" needs to be supplied before calling function ..
//---------------------------------------------------------------------------------------------

// ** Get the size of the array before calling the function
// int patternSize = sizeof(pattern) / sizeof(pattern[0]);

//---------------------------------------------------------------------------------------------
// ** Search for byte pattern inside a bigger byte array (loaded from a file into a buffer)
//---------------------------------------------------------------------------------------------
unsigned int FindBytePattern(unsigned char *pattern, unsigned char *fileBuffer, unsigned int fileSize, unsigned int patternSize)
{	
// ** Create strings
	std::string needle(pattern, pattern + patternSize);
    std::string haystack(fileBuffer, fileBuffer + fileSize);
    
    unsigned int offsetPos = haystack.find(needle);                                                             
    return offsetPos;
};
//---------------------------------------------------------------------------------------------
// ** END: Search for byte pattern
//---------------------------------------------------------------------------------------------



/*
//---------------------------------------------------------------------------------------------
// ** EXAMPLE USAGE
//---------------------------------------------------------------------------------------------

#include <stdio.h>
#include <string>
#include "FindBytePattern.h"


int main()
{	
	// ** String containing filename
	std::string strFileName = "myfile.bin";

	// ** Try to open file for reading (binary)
	FILE *pFile = NULL;
	errno_t errorCode = fopen_s(&pFile, strFileName.c_str(), "rb");

	if (pFile != NULL)
	{
		fseek(pFile, 0, SEEK_END);
		unsigned int uFileSize = ftell(pFile);
		rewind(pFile);

		unsigned char *cBuf = (unsigned char*)malloc(uFileSize * sizeof(unsigned char*));

		if (cBuf != NULL)
		{
			fread(cBuf, 1, uFileSize, pFile); // Read file into buffer 1 byte at a time
			fclose(pFile);
			pFile = NULL;
		}

		// ** Byte pattern to search for
		unsigned char hexstr[] = { 0x00, 0x48, 0x65, 0x61, 0x6C, 0x74, 0x68, 0x00, 
								   0x0C, 0x00, 0x00, 0x00, 0x49, 0x6E, 0x74, 0x50,
								   0x72, 0x6F, 0x70, 0x65, 0x72, 0x74, 0x79, 0x00 };

		// ** Get the size of array
		int patternSize = sizeof(hexstr) / sizeof(hexstr[0]);

		// ** Search for hexstring in buffer
		unsigned int nOffsetPos = FindBytePattern(hexstr, cBuf, uFileSize, patternSize);

		// ** Check if we found pattern or not
		if(nOffsetPos != std::string::npos)
		{
			// ** OffsetPos is starting position of found pattern
			printf("Pattern found at offset: %d ( 0x%x )\n", nOffsetPos, nOffsetPos);

			// ** Get the value and put into integer
			unsigned int hexValue[5];

			hexValue[0] = cBuf[nOffsetPos + 33]; // Get byte value that is offset by 33 from nOffsetPos
			hexValue[1] = cBuf[nOffsetPos + 34]; // Get byte value that is offset by 34 from nOffsetPos
			hexValue[2] = cBuf[nOffsetPos + 35]; // Get byte value that is offset by 35 from nOffsetPos

			printf("%x%x%x\n", hexValue[0], hexValue[1], hexValue[2]);
		}
		else if (nOffsetPos == std::string::npos)
		{
			printf("Pattern not found!\nReturn value: %d ( 0x%x )\n", nOffsetPos, nOffsetPos);
		}

		// ** Clean up
		free(cBuf);
    }
	else
	{
		printf("Error opening file!\nErrorcode: %d", errorCode);
	}

	// ** Pause before exit
	getchar();

	return 0;
};

//---------------------------------------------------------------------------------------------
// ** END: EXAMPLE USAGE
//---------------------------------------------------------------------------------------------

*/
