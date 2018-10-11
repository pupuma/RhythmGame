#pragma once

class Album;


class BMSParsing
{
private:
	Album* album;
public:
	BMSParsing(const char* FileName);
	~BMSParsing();
};