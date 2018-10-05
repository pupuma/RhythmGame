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
		sprintf_s(filePath, "../Resources/BMS/Blood Tales/%s.bms", FileName);

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

		std::string sRecord;

		// MusicAlbum Info
		int iPlayerCount = 0;
		std::string sGenre;
		std::string sTitle;
		std::string sArtist;
		int iBpm = 0;
		int iPlayLevel = 0;
		int iRank = 0;
		int iTotal = 0;
		std::string sStageFile;
		std::string sBmp;
		int iBmpNumber = 0;
		int iDifficulty = 0;
		std::string sBanner;
		std::string sSubArtist;

		// MusicAlbum Wav
		std::string sWavName;
		std::string sWavIndex;

		// Note Data
		int iMusicNode;
		std::string sChannelIndex;
		std::string sMusicData;

		std::string sToken;

		while (!q_data.empty())
		{
			// 
			sRecord = q_data.front();
			if (sRecord.substr(0, 1) == "#")
			{
				//std::cout << sRecord << std::endl;

				if (sRecord.substr(1, 6) == "PLAYER")
				{
					sToken = sRecord.substr(7);
					iPlayerCount = atoi(sToken.c_str());
					std::cout << "playerCount : " << iPlayerCount << std::endl;
				}
				else if (sRecord.substr(1, 5) == "GENRE")
				{
					sToken = sRecord.substr(6);
					sGenre = sToken;
					std::cout << "Genre : " << sGenre << std::endl;
				}
				else if (sRecord.substr(1, 5) == "TITLE")
				{
					sToken = sRecord.substr(6);
					sTitle = sToken;
					std::cout << "Title : " << sTitle << std::endl;
				}
				else if (sRecord.substr(1, 6) == "ARTIST")
				{
					sToken = sRecord.substr(7);
					sArtist = sToken;
					std::cout << "Artist : " << sArtist << std::endl;
				}
				else if (sRecord.substr(1, 3) == "BPM")
				{
					sToken = sRecord.substr(4);
					iBpm = atoi(sToken.c_str());
					std::cout << "BPM : " << iBpm << std::endl;
				}
				else if (sRecord.substr(1, 9) == "PLAYLEVEL")
				{
					sToken = sRecord.substr(10);
					iPlayLevel = atoi(sToken.c_str());
					std::cout << "PlayLevel : " << iPlayLevel << std::endl;
				}
				else if (sRecord.substr(1, 4) == "RANK")
				{
					sToken = sRecord.substr(5);
					iPlayLevel = atoi(sToken.c_str());
					std::cout << "Rank : " << iPlayLevel << std::endl;
				}
				else if (sRecord.substr(1, 5) == "TOTAL")
				{
					sToken = sRecord.substr(6);
					iTotal = atoi(sToken.c_str());
					std::cout << "Total : " << iTotal << std::endl;
				}
				else if (sRecord.substr(1, 9) == "STAGEFILE")
				{
					sToken = sRecord.substr(10);
					sStageFile = sToken;
					std::cout << "StageFileName : " << sStageFile << std::endl;
				}
				else if (sRecord.substr(1, 3) == "BMP")
				{
					sToken = sRecord.substr(5);
					sBmp = sToken;
					sToken = sRecord.substr(4, 2);
					iBmpNumber = atoi(sToken.c_str());
					std::cout << "BMP [ " << iBmpNumber << " ] : " << sBmp << std::endl;
				}
				else if (sRecord.substr(1, 10) == "DIFFICULTY")
				{
					sToken = sRecord.substr(11);
					iDifficulty = atoi(sToken.c_str());
					std::cout << " Difficulty : " << iDifficulty << std::endl;
				}
				else if (sRecord.substr(1, 6) == "BANNER")
				{
					sToken = sRecord.substr(7);
					sBanner = sToken;
					std::cout << " Banner : " << sBanner << std::endl;
				}
				else if (sRecord.substr(1, 9) == "SUBARTIST")
				{
					sToken = sRecord.substr(10);
					sSubArtist = sToken;
					std::cout << " SubArtist : " << sSubArtist << std::endl;
				}
				else if (sRecord.substr(1, 3) == "WAV")
				{
					sToken = sRecord.substr(4, 2);
					sWavIndex = sToken;
					sToken = sRecord.substr(7);
					sWavName = sToken;
					std::cout << " Wav [ " << sWavIndex << " ] : " << sWavName << std::endl;
				}
				else
				{
					// Note Data
					sToken = sRecord.substr(1, 3);
					iMusicNode = atoi(sToken.c_str());
					sToken = sRecord.substr(4, 2);
					sChannelIndex = sToken;
					sToken = sRecord.substr(7);
					sMusicData = sToken;
					std::cout << "MusicNode [ " << iMusicNode << " ] " <<
						" ChannelIndex [ " << sChannelIndex << " ] : " <<
						sMusicData << std::endl;
					//1.
					// 여기서 노트를 백터에 넣는다? 
					// Node? -> 001/ 002/ 003/ 004 / 005/ ..../
					// 노드 별로 배치

					// 2.
					// 배경음 트랙 
				}
			}
			q_data.pop();
		}


		
	}
}
BMSParsing::~BMSParsing()
{

}