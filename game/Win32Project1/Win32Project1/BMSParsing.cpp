#include "BMSParsing.h"
#include <fstream>	
#include <queue>
#include <string>
#include <iostream>

BMSParsing::BMSParsing(const char* FileName)
{
	// Parsing 
	{
		// 
		char filePath[256];
		sprintf(filePath, "../Resources/BMS/_sp_chilltrap_/%s.bmx", FileName);

		std::string sRecord;
		std::queue<std::string> q_data;
		std::ifstream inFile(filePath);

		
		if (!inFile.is_open())
		{
			std::cout << " File is Not Read " << std::endl;
		}

		
		while (getline(inFile, sRecord))
		{
			std::cout << sRecord << std::endl;
		}


		inFile.close();

	}

}
BMSParsing::~BMSParsing()
{

}