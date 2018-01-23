#include <iostream>
#include <string>
#include <vector>
#include "Song.h"

using namespace std;

void printCatalog(vector <Song> songLibrary);
vector <string> searchArtist(vector <Song> songLibrary, string artistSearch);

int main() {

	//VARIABLE DECLARATIONS
	vector <Song> songLibrary;
	Song songInput;
	string title;
	
	Song song("title", "album", "artis", 3, Classical);
	songLibrary.push_back(song);
	Song song1("title1", "album1", "artis1", 4, Rock);
	songLibrary.push_back(song1);
	Song song2("title6", "album4", "artis4", 7, Classical);
	songLibrary.push_back(song2);
	Song song3("title5", "album5", "artis5", 2, Classical);
	songLibrary.push_back(song3);
	Song song4("title2", "album2", "artis2", 5, Jazz);
	songLibrary.push_back(song4);
	Song song5("title3", "album3", "artis3", 6, Classical);
	songLibrary.push_back(song5);
	Song song6("title8", "album4", "artis4", 7, Classical);
	songLibrary.push_back(song6);
	Song song7("title5", "album5", "artis5", 2, Classical);
	songLibrary.push_back(song7);

	song.sortSong(songLibrary, 0, songLibrary.size()-1);

	cout << "Enter Title of the Song to search in the library: ";
	cin >> title;

	int track = song.findSong(songLibrary, title, 0, songLibrary.size());

	if (track == -1)
	{
		char c;
		cout << "Song not Found!";
		cout << "\nWould you like to add this Song? (y/n): ";
		cin >> c;
		if (c == 'Y' || c == 'y')
			{
			cout << "\n\n Enter Song you want to search in the following format:";
			cout << "\n Input format: Title Album Artist PlayTime(mins) Category Option(1,2,3,4,5)";
			cout << "\n Category Options: 1)Pop 2)Rock 3)Classical 4)Jazz 5)HipHop";
			cout << " \n----------------------------------------------------------------\n";
			cin >> songInput;
			songLibrary.push_back(songInput);
			cout << "\n New Song added to the Library!\n\n";

			songInput.sortSong(songLibrary, 0, songLibrary.size() - 1);
			printCatalog(songLibrary);
			

			}

	}
	else cout << endl << songLibrary[track] << endl;

	
	
	return 0;

}

//FUNCTION DEFINITION FOR PRINT CATALOF FUNCTION
void printCatalog(vector <Song> songLibrary) 
{
	for (int i = 0; i < songLibrary.size(); i++)
		cout << songLibrary[i];
}

//FUNTCION DEFINITION FOR SEARCH ARTIST FUNCTION
vector <string> searchArtist(vector <Song> songLibrary, string artistSearch)
{
	vector <string> songList;
	for (int i = 0; i < songLibrary.size(); i++)
	{	

		if (artistSearch == songLibrary[i].getArtist())
			songList.push_back(songLibrary[i].getTitle());
	}

	return songList;
}



/*
vector <string> songList;
Song songInput;
string artistSearch, songSearch;
int n;

cout << "\nEnter number of Songs you want to enter: ";
cin >> n;

//DISPLAY USER INPUT FORMAT
cout << "\n\n Enter Songs in the following format:";
cout << "\n Input format: Title Album Artist PlayTime(mins) Category Option(1,2,3,4,5)";
cout << "\n Category Options: 1)Pop 2)Rock 3)Classical 4)Jazz 5)HipHop";
cout << " \n----------------------------------------------------------------\n";

//USER INPUT AND PUSH DATA INTO VECTOR
for (int i = 0; i < n; i++)
{
cout << "\n Enter Song Information (" << i+1 << "): ";
cin >> songInput;
songLibrary.push_back(songInput);
}

//DISPLAY VECTOR LIST USING PRINTCATALOG FUNCTION
cout << "Displaying Song Library: ";
printCatalog(songLibrary);

//ARTIST SEARCH
cout << "\nEnter Name of the Artist to search for songs: ";
cin >> artistSearch;
songList = searchArtist(songLibrary, artistSearch);

if (songList.size() > 0)
{
cout << "\nSongs of the artist you entered:\n";
for (int i = 0; i < songList.size(); i++)
cout << songList[i] << endl;
}
else
{
cout << "\nNo Songs found of the artist you entered.\n";
}

//SONG SEARCH
cout << "\n\n Enter Song you want to search in the following format:";
cout << "\n Input format: Title Album Artist PlayTime(mins) Category Option(1,2,3,4,5)";
cout << "\n Category Options: 1)Pop 2)Rock 3)Classical 4)Jazz 5)HipHop";
cout << " \n----------------------------------------------------------------\n";
cin >> songInput;
cout << endl;

bool found = false;
for (int i = 0; i < songLibrary.size(); i++)
{
if (songInput == songLibrary[i]) found = true;
}

if (found) cout << "\nSong Found in the Library!\n\n";
else cout << "\nSong not found in the Library!\n\n";


*/