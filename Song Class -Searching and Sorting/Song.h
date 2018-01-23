#ifndef _SONG_H
#define _SONG_H

#include<string>
#include<vector>

using  namespace std;

//Defining Genre Enum
enum Genres { Rock, Pop, Classical, Hiphop, Jazz, Undefined };

class Song {

public:

	//Constructors
	Song();													//Default constructor
	Song(string, string, string, unsigned  int, Genres);	//Alternate constructor

	//Mutators
	void setTitle(string);
	void setAlbum(string);
	void setArtist(string);
	void setPlayime(unsigned int);
	void setCategory(int);

	//Inspectors
	string getTitle() const;
	string getAlbum() const;
	string getArtist() const;
	unsigned int getPlaytime() const;
	Genres getCategory() const;

	//Facilitator
	string getString(Genres) const;
	string getSongData() const;

	//Sort using Quick Sort
	void sortSong(vector<Song> &v, int low, int high );
	int partition(vector<Song> &v, int low, int high);

	//Search using Binary Search
	int findSong(vector<Song> v, string title, int low, int high) const;


private:

	//Attributes of this class
	string title_;				//title of the song
	string album_;				//album of the song
	string artist_;				//artist of the song
	unsigned int play_time_;	//play time of the song in minutes
	Genres category_;			//category / genre of the song

};

bool operator == (Song s1, Song s2);
bool operator != (Song s1, Song s2);
istream &operator >> (istream& in, Song &song);
ostream &operator << (ostream& out, Song &song);

#endif 
