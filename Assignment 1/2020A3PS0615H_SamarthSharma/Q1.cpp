//SAMARTH SHARMA 2020A3PS0615H

#include<bits/stdc++.h>
using namespace std;

class GameEntry { 
    public:
    	GameEntry(const string &n = "", int s = 0); 
    	string getName() const;						
    	int getScore() const;						
    private:
    	string name; 
    	int score;	 
};
GameEntry::GameEntry(const string &n, int s) : name(n), score(s) {
}
string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }
class Scores { 
    public:
    	Scores(int maxEnt = 3);				  
    	~Scores();								  
    	void add(const GameEntry &e);			  
    	GameEntry remove(int i) ; 
    	void printAllScores();
    private:
    	int maxEntries;		// MAX no Entries
    	int numEntries;		// Actual Entries
    	GameEntry *entries;     // Array of game entries
};
Scores::Scores(int maxEnt) {			 // constructor
	maxEntries = maxEnt;				 // save the max size
	entries = new GameEntry[maxEntries]; // allocate array storage
	numEntries = 0;						 // initially no elements
}
Scores::~Scores() { 
	delete[] entries;
}
void Scores::add(const GameEntry &e) {
	int newScore = e.getScore(); // score to add
	if (numEntries == maxEntries) { // the array is full
		if (newScore <= entries[maxEntries - 1].getScore())
			return; // not high enough - ignore
	}
	else
		numEntries++; // if not full, one more entry
		cout<<"Number of entries: "<<numEntries<<endl;
	    int i = numEntries - 2; // start with the next to last
	   
    	entries[i + 1] = e; 
}
GameEntry Scores::remove(int i) 
{
	if ((i < 0) || (i >= numEntries))
		throw("IndexOutOfBounds - Invalid index");
	GameEntry e = entries[i]; 
	GameEntry temp = entries[numEntries-1];
	entries[numEntries-1] = entries[i];
	entries[i] = temp;
	
	
	numEntries--;					
	return e;						
}
void Scores::printAllScores()
{
	for (int i = 0; i < numEntries; i++)
	{
		cout << entries[i].getName() << " : " << entries[i].getScore() << "\n";
	}
}
void showOptions()
{
	cout
		<< "1:	Add Player\n"
		<< "2:	Remove Player By Index\n"
		<< "3:	Print Scores\n"
		<< "4:	Exit\n";
}
int main()
{
	Scores scoresObj;
	int option;
	string playerName;
	int score;

	while (1)
	{
		showOptions();
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "Enter Player Name and Score\n";
			cin >> playerName >> score;
			scoresObj.add(GameEntry(playerName, score));
			break;
		case 2:
			int index;
			cout << "Enter the index\n";
			cin >> index;
			scoresObj.remove(index);
			break;
		case 3:
			scoresObj.printAllScores();
			break;
		case 4:
			return EXIT_SUCCESS;
			
		default :
		    cout<<"wrong input, Try again"<< endl;
		    continue;
		    
		}
		
	}
}