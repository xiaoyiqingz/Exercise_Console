#include "Shellwc.h"

#include <iostream>
#include <Shlwapi.h>

namespace test{

const int WORDS  = 1;
const int LINES  = 2;
const int CHARCS = 4;

int CompraseArg(TCHAR* parg)
{
	if (_tcscmp(parg, _T("-w")) == 0) {
		return WORDS;
	} else if (_tcscmp(parg, _T("-l")) == 0) {
		return LINES;
	} else if (_tcscmp(parg, _T("-c")) == 0) {
		return CHARCS;
	}

	return 0;
}

void Shellwc(int argc, _TCHAR* argv[])
{
	int nMode = 0;
	int nPos = 0;
	for (int i = 1; i < argc; i++) {
		int res = 0;
		if (res = CompraseArg(argv[i])) {
			nMode += res;
		} else {
			nPos = i;
			break;
		}
	}

	int nWords = 0;
	int nLines = 0;
	int nChars = 0;

	for (int i = nPos; i < argc; i++) {
		if (PathFileExists(argv[i]) && !PathIsDirectory(argv[i])) {
			HANDLE hFile = CreateFile(argv[i], GENERIC_READ, 0, NULL, OPEN_EXISTING,
				FILE_ATTRIBUTE_NORMAL, NULL);

			if (hFile == INVALID_HANDLE_VALUE) {
				std::cout << "ReadFile Error" << argv[i] << std::endl;
				getchar();
				continue;
			}


		}
	}	
}

}   //namespace test