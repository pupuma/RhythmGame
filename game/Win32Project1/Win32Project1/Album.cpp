#include "Album.h"
#include <iostream>

#include "Wave.h"

Album::Album()
{

}

Album::~Album()
{

}

void Album::Init(std::string genre, std::string title, std::string artist, std::string stageFile, std::string bmp, std::string banner, std::string subArtist,
	int playerCount, int bpm, int playerLevel, int rank, int total, int bmpNumber, int difficulty)
{
	sGenre = genre;
	sTitle = title;
	sArtist = artist;
	sStageFile = stageFile;
	sBmp = bmp;
	sBanner = banner;
	sSubArtist = subArtist;
	_playerCount = playerCount;
	_bpm = bpm;
	_playerLevel = playerLevel;
	_rank = rank;
	_total = total;
	_bmpNumber = bmpNumber;
	_difficulty = difficulty;
	AlbumDataPrint();
}

DLinkedList<MusicNode*> Album::GetMusicNodeList()
{
	return DLinkedList<MusicNode*>();
}

void Album::AlbumDataPrint()
{
	std::cout << "playerCount : " << _playerCount << std::endl;
	std::cout << "Genre : " << sGenre << std::endl;
	std::cout << "Title : " << sTitle << std::endl;
	std::cout << "Artist : " << sArtist << std::endl;
	std::cout << "BPM : " << _bpm << std::endl;
	std::cout << "PlayLevel : " << _playerLevel << std::endl;
	std::cout << "Rank : " << _rank << std::endl;
	std::cout << "Total : " << _total << std::endl;
	std::cout << "StageFileName : " << sStageFile << std::endl;
	std::cout << "BMP [ " << _bmpNumber << " ] : " << sBmp << std::endl;
	std::cout << " Difficulty : " << _difficulty << std::endl;
	std::cout << " Banner : " << sBanner << std::endl;
	std::cout << " SubArtist : " << sSubArtist << std::endl;
}

void Album::AddWav(std::string indexName, std::string sWavName)
{
	_wave = new Wave();
	_wave->Init(indexName, sWavName);
	_waveList.push_back(_wave);
}