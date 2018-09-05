#pragma once
#include "DLinkedList.h"
#include <string>
#include <vector>

class MusicNode;
class Wave;

class Album
{
private:
	std::string sGenre;
	std::string sTitle;
	std::string sArtist;
	std::string sStageFile;
	std::string sBmp;
	std::string sBanner;
	std::string sSubArtist;
	int _playerCount;
	int _bpm;
	int _playerLevel;
	int _rank;
	int _total;
	int _bmpNumber;
	int _difficulty;
private:
	Wave* _wave;
private:
	DLinkedList<MusicNode*> _nodeList;
	std::vector<Wave*> _waveList;
public:
	Album();
	~Album();
public:
	void Init(std::string genre, std::string title, std::string artist,
		std::string stageFile, std::string bmp, std::string banner,
		std::string subArtist, int playerCount, int bpm, int playerLevel,
		int rank, int total, int bmpNumber, int difficulty);
public:
	DLinkedList<MusicNode*> GetMusicNodeList();
	void AlbumDataPrint();
public:
	void AddWav(std::string indexName, std::string sWavName);
};