#include <iostream>

using namespace std;

int main()
{
	string notesArray[12] = { "A","#A","B","C","C#","D","D#","E","F","F#","G","G#" };
	
	for (int i = 0; i < 12; i++)
	{
		string firstNote = notesArray[i];
		string secondNote = notesArray[(i + 4) % 12];
		string thirdNote = notesArray[(i + 7) % 12];
		string triadsArray = firstNote + "\t" + secondNote + "\t" + thirdNote;
		cout << triadsArray << endl;
	}
}