#include "Dictionary.h"

#include<string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include<bits/stdc++.h> 


using namespace std;
	
	/* The constructor gets passed the name of the file from which
	   to read the word list. */
Dictionary::Dictionary(string dictionary_file_name)
{
	//read dictionary.txt
	//for each word in the file, insert into the set
	ifstream inFile;
	string next; 

	inFile.open(dictionary_file_name);
	if (!inFile)
	{
		cout << "Error with File";
	}

	while (inFile >> next) {
       words.insert(next);

    }

    inFile.close();
}

Dictionary::~Dictionary ()
{

}

	/* Checks whether the given word is in the dictionary, and returns true if so.
	   Case should not matter. Must run in O(logn) for the number of words in the dictionary. */
bool Dictionary::isLegalWord (string const &word) const
{
	set <string>::iterator it;

	string lower = word;

	transform(lower.begin(), lower.end(), lower.begin(), ::tolower); 

	it = words.find(lower);
	if(it !=words.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	Dictionary dict("dictionary.txt");

	string hello = "HeLlo";
	cout << dict.isLegalWord(hello);

}