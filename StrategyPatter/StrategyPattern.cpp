// RTSP_Practice.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include<iostream>
using namespace std;

class Video {
public:
	virtual void Encoder() = 0;
};
class Audio {
public:
	virtual void Encoder() = 0;
};
class MetaData {
public:
	virtual void Parse() = 0;
};
//-------------------------------------------------------------------------
class H264 : public Video {
public:
	void Encoder() { cout << "Stat Video Encoder with H264..." << endl; }
};
class H265 : public Video {
public:
	void Encoder() { cout << "Stat Video Encoder with H265..." << endl; }
};
class MJPEG : public Video {
public:
	void Encoder() { cout << "Stat Video Encoder with MJPEG..." << endl; }
};

class AAC : public Audio {
public:
	void Encoder() { cout << "Stat Audio Encoder with AAC..." << endl; }
};
class WMA : public Audio {
public:
	void Encoder() { cout << "Stat Audio Encoder with WMA..." << endl; }
};

class XML : public MetaData {
public:
	void Parse() { cout << "Parse XML...." << endl; }
};
class JSON : public MetaData {
public:
	void Parse() { cout << "Parse JASON...." << endl; }
};
// ------------------------------------------------------------------------
class Media {
public:
	Media(Video *, Audio *, MetaData *);
	void RunVideo() { m_video->Encoder(); }
	void RunAudio() { m_audio->Encoder(); }
	void RunMetadata() { m_metadata->Parse(); }

protected:
	Video * m_video;
	Audio * m_audio;
	MetaData *m_metadata;
};
Media::Media(Video *video, Audio *audio, MetaData *metadata) {
	m_video = video;
	m_audio = audio;
	m_metadata = metadata;
}
//-----------------------------------------------------------------------------------------------------------------
int main() {
	Video *h264 = new H264();
	Audio *aac = new AAC();
	MetaData *xml = new XML();

	Media media(h264, aac, xml);
	media.RunVideo();
	media.RunAudio();
	media.RunMetadata();

	delete xml;
	delete aac;
	delete h264;
	system("pause");
	return 0;
}