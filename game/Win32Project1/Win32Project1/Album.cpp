#include "Game.h"
#include "Album.h"

Album::Album()
{

}

Album::~Album()
{

}

void Album::AlbumInfo(int _playerCount, std::string _genre, std::string _title, std::string _artist, int _bpm, int _playLevel, int _rank, int _total, std::string _stageFile, std::string _bmp, int _bmpNumber, int _difficulty, std::string _banner, std::string _subArtist)
{
	iPlayerCount = _playerCount;
	sGenre = _genre;
	sTitle = _title;
	sArtist = _artist;
	iBpm = _bpm;
	iPlayLevel = _playLevel;
	iRank = _rank;
	iTotal = _total;
	sStageFile = _stageFile;
	sBmp = _bmp;
	iBmpNumber = _bmpNumber;
	iDifficulty = _difficulty;
	sBanner = _banner;
	sSubArtist = _subArtist;
}

void Album::AddAlbumWav(std::string _wavIndex, std::string _wavName)
{
	mWavList.insert({ _wavIndex, _wavName });
}

void Album::AddMusicData(int _musicNode, std::string _channelIndex, std::string _musicData)
{
	musicData.iMusicNode = _musicNode;
	musicData.sChannelIndex = _channelIndex;
	musicData.sMusicData = _musicData;

	q_MusicDataList.push(musicData);
}
