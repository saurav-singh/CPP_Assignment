#include <string>
#include <sstream>
#include <vector>
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
	default:
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

void Song::setCategory(int choice)
{
	switch (choice)
	{
	case 1:
		category_ = Pop;
		break;
	case 2:
		category_ = Rock;
		break;
	case 3:
		category_ = Classical;
		break;
	case 4:
		category_ = Jazz;
		break;
	case 5:
		category_ = Hiphop;
		break;
	default:
		category_ = Undefined;
		break;
	}
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
		<< "\n Play Time: " << play_time_ << " minute(s)" << "\n Category: " << getString(category_) << "\n";

	return(os.str());

}


//Sort function Implementation
void Song::sortSong(vector<Song> &v, int low, int high)
{
	
	if (low < high)
	{
		int p = partition(v, low, high);
		sortSong(v, low, p);
		sortSong(v, p + 1, high);
	}


}

//Partition function implementation
int Song::partition(vector<Song> &v, int low, int high) 
{
	string pivot = v[low].getTitle();
	int i = low - 1;
	int j = high + 1;

	while (true)
	{
		do {
			i = i + 1;
		} while (v[i].getTitle() < pivot);

		do {
			j = j - 1;
		} while (v[j].getTitle() > pivot);

		if (i >= j) return j;

		swap(v[i], v[j]);
	}


}

//Search function Implementation
int Song::findSong(vector<Song> v, string title, int low, int high) const
{
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (v[mid].getTitle() < title)
			return findSong(v, title, mid + 1, high);

		else if (v[mid].getTitle() > title)
			return findSong(v, title, low, mid - 1);

		else return mid;
	}

	return -1;

}


//Bool Operator Overloading
bool operator == (Song s1, Song s2)
{
	if (s1.getTitle() == s2.getTitle())
		if (s1.getAlbum() == s2.getAlbum())
			if (s1.getArtist() == s2.getArtist())
				if (s1.getPlaytime() == s2.getPlaytime())
					if (s1.getCategory() == s2.getCategory())
						return true;
	return false;
}

bool operator != (Song s1, Song s2)
{
	if (s1.getTitle() == s2.getTitle())
		if (s1.getAlbum() == s2.getAlbum())
			if (s1.getArtist() == s2.getArtist())
				if (s1.getPlaytime() == s2.getPlaytime())
					if (s1.getCategory() == s2.getCategory())
						return false;
	return true;

}


//IO Operator Overloading
istream &operator >> (istream& in, Song &song)
{
	//Input format: Title, Album, Artist, Play Time, Category
	string title, album, artist;
	int play_time, category;

	in >> title >> album >> artist >> play_time >> category;
	song.setTitle(title);
	song.setAlbum(album);
	song.setArtist(artist);
	song.setPlayime(play_time);
	song.setCategory(category);

	return in;
}

ostream &operator << (ostream& out, Song &song)
{
	out << "\n Song Detail:" << "\n --------------------"
		<< "\n Titile: " << song.getTitle() << "\n Album: " << song.getAlbum() << "\n Artist: " << song.getArtist()
		<< "\n Play Time: " << song.getPlaytime() << " minute(s)" << "\n Category: " << song.getString(song.getCategory()) << "\n";

	return out;
}