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
	void Encoder() { cout << "Stat Video Encoder with H264" << endl; }
};
class H265 : public Video {
public:
	void Encoder() { cout << "Stat Video Encoder with H265" << endl; }
};
class MJPEG : public Video {
public:
	void Encoder() { cout << "Stat Video Encoder with MJPEG" << endl; }
};
class JPEG : public Video {
public:
	void Encoder() { cout << "Start Video Encoder with JPEG" << endl; }

};

class AAC : public Audio {
public:
	void Encoder() { cout << "Stat Audio Encoder with AAC" << endl; }
};
class WMA : public Audio {
public:
	void Encoder() { cout << "Stat Audio Encoder with WMA" << endl; }
};
class MP3 : public Audio {
public:
	void Encoder() { cout << "Start Audio Encoder with MP3" << endl; }
};

class XML : public MetaData {
public:
	void Parse() { cout << "Parse XML" << endl; }
};
class JSON : public MetaData {
public:
	void Parse() { cout << "Parse JASON" << endl; }
};

// ------------------------------------------------------------------------
class Media {
public:
	Media(shared_ptr<Video> video, shared_ptr<Audio> audio, shared_ptr<MetaData> metadata);
	void RunVideo() { m_video->Encoder(); }
	void RunAudio() { m_audio->Encoder(); }
	void RunMetadata() { m_metadata->Parse(); }

protected:
	shared_ptr<Video> m_video;
	shared_ptr<Audio> m_audio;
	shared_ptr<MetaData> m_metadata;
};
Media::Media(shared_ptr<Video> video, shared_ptr<Audio> audio, shared_ptr<MetaData> metadata) {
	m_video = video;
	m_audio = audio;
	m_metadata = metadata;
}
//-----------------------------------------------------------------------------------------------------------------
int main() {
	shared_ptr<Video> h264(new H264());
	shared_ptr<Audio> aac(new AAC());
	shared_ptr<MetaData> xml(new XML());

	shared_ptr<Video> jpeg(new JPEG());
	shared_ptr<Audio> mp3(new MP3());
	shared_ptr<MetaData> json(new JSON());

	Media media(h264, aac, xml);
	media.RunVideo();
	media.RunAudio();
	media.RunMetadata();

	cout << "New Track..." << endl;
	Media media2(jpeg, mp3, json);
	media2.RunVideo();
	media2.RunAudio();
	media2.RunMetadata();


	system("pause");
	return 0;
}