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
		sprintf_s(filePath, "../Resources/BMS/_sp_chilltrap_/%s.bmx", FileName);

		std::string sBuffer;
		std::queue<std::string> q_data;
		std::ifstream inFile(filePath);


		
		if (!inFile.is_open())
		{
			std::cout << " File is Not Read " << std::endl;
		}

		
		while (getline(inFile, sBuffer))
		{
			//std::cout << sBuffer << std::endl;
			q_data.push(sBuffer);
		}

		inFile.close();

		// Data
		while (!q_data.empty())
		{
			
			// Info


			//WAV
			if (q_data.front().substr(0, 4) == "#WAV")
			{
				std::cout << q_data.front() << std::endl;

			}
			q_data.pop();

			
		}

	}

}
BMSParsing::~BMSParsing()
{

}