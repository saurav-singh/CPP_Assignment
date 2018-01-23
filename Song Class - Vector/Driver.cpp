#include <iostream>
#include <string>
#include <vector>
#include "Song.h"

using namespace std;

void printCatalog(vector <Song> songLibrary);
vector <string> searchArtist(vector <Song> songLibrary, string artistSearch);

void main() {

	//VARIABLE DECLARATIONS
	vector <Song> songLibrary;
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

