#pragma once

class Album
{
private:
	struct tagMusicData
	{
		int iMusicNode;
		std::string sChannelIndex;
		std::string sMusicData;
	};

private:
	std::vector<tagMusicData*> vMusicDataList;
	std::queue<tagMusicData> q_MusicDataList;
	
private:
	tagMusicData* musicData;
	// MusicAlbum Info
	int iPlayerCount;
	std::string sGenre;
	std::string sTitle;
	std::string sArtist;
	int iBpm;
	int iPlayLevel;
	int iRank;
	int iTotal;
	std::string sStageFile;
	std::string sBmp;
	int iBmpNumber;
	int iDifficulty;
	std::string sBanner;
	std::string sSubArtist;
	
private:
	std::map<std::string, std::string> mWavList;
public:
	Album();
	~Album();
public:
	// ������ �⺻ ���� ���� 
	void AlbumInfo(int _playerCount , std::string _genre, std::string _title, std::string _artist,
		int _bpm, int _playLevel, int _rank,
		int _total, std::string _stageFile, std::string _bmp,
		int _bmpNumber, int _difficulty, std::string _banner, std::string _subArtist);

	// 
	void AddAlbumWav(std::string _wavIndex, std::string _wavName);
	void AddMusicData(int _musicNode, std::string _channelIndex, std::string _musicData);
public:
	// ���� ���� 
	int GetMusicNodeSize();
	int GetAlbumBpm();
public:
	std::vector<tagMusicData*> GetQueTest() { return vMusicDataList; }
	std::map<std::string, std::string> GetMusicWaveList() { return mWavList; }
};