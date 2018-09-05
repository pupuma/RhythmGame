#pragma once
#include "DLinkedList.h"

class MusicNode;

class Album
{
public:
	Album();
	~Album();
public:
	DLinkedList<MusicNode*> GetMusicNodeList();
};