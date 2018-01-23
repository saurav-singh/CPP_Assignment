#include <string>
#include <sstream>
#include "Song.h"

using namespace std;

//Constructors Implementation
Song::Song()
{

	title_ = "UNDEFINED_TITLE";
	album_ = "UNDEFINED_ALBUM";
	artist_ = "UNDEFINED_ARTIST";
	play_time_ = 0;
	category_ = Undefined;

}

Song::Song(string title, string album, string artist, unsigned int play_time, Genres category)
{

	title_ = title;
	album_ = album;
	artist_ = artist;
	play_time_ = play_time;
	category_ = category;

}

//Enums to String
string Song::getString(Genres c) const
{

	switch (c) {
	case Rock:
		return "Rock";
		break;
	case Pop:
		return "Pop";
		break;
	case Classical:
		return "Classical";
		break;
	case Hiphop:
		return "Hiphop";
		break;
	case Jazz:
		return "Jazz";
		break;
	case Undefined:
		return "Undefined";
		break;

	}
}

//Mutator Implementation
void Song::setTitle(string title)
{
	title_ = title;
}

void Song::setAlbum(string album)
{
	album_ = album;
}

void Song::setArtist(string artist)
{
	artist_ = artist;
}

void Song::setPlayime(unsigned int play_time)
{
	play_time_ = play_time;
}

void Song::setCategory(Genres category)
{
	category_ = category;
}


//Inspector Implementation

string Song::getTitle() const
{
	return title_;
}

string Song::getAlbum() const
{
	return album_;
}

string Song::getArtist() const
{
	return artist_;
}

unsigned int Song::getPlaytime() const
{
	return play_time_;
}

Genres Song::getCategory() const
{
	return category_;
}

//Facilitator Implementation
string Song::getSongData() const
{

	ostringstream os;

	os << "\n Song Detail:" << "\n --------------------"
		<< "\n Titile: " << title_ << "\n Album: " << album_ << "\n Artist: " << artist_
		<< "\n Play Time: " << play_time_ << " minute(s)" << "\n Category: " << getString(category_) << "\n\n";

	return(os.str());

}
