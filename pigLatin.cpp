#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

//precondition: Needs existing file and an empty vector to fill
//postcondition: the phrase from the doc has been put into the vector of type char
void fillVector(vector<char>& v, string fileName);
//precondition: A vector is sent in and because it's on a loop it also later sends in the place and counts up the characters
//postcondition: A new word is created and put onto the screen that is translated to pig latin. Also counts up characters and letters.
void getWord(vector<char>& phrase, int& letters, int& characters, int& place);
//precondition: sends in a char
//postcondition: Returns if that character is a vowel or not
bool isVowel(char letter);
//precondition: a vector of characters is sent in
//postcondition: the vector is outputted as a word
void printVector(vector<char> v);

int main()
{
	//declarations
	int words = 0, letters = 0, characters = 0, place = 0;
	
	vector <char> phrase;
	//taking  in the file
	string fileName;
	cout << "Please enter name of the text file: ";
	cin >> fileName;
	fillVector(phrase, fileName);
	
	//count words
	for (int h = 0; h < phrase.size(); h++)
	{
		if (phrase[h] == ' ')
			words++;
	}
	//runs a loop that gets the words translated one at a time and put on screen
	for (int i = 0; i < words; i++)
	{
		getWord(phrase, letters, characters, place);
	}
	//fix 1 off bug
	characters--;
	//output
	cout << endl << endl;
	cout << "words: " << words << endl;
	cout << "letters: " << letters << endl;
	cout << "characters: " << characters << endl;
}

void getWord(vector<char>& phrase, int& letters, int& characters, int& place)
{
	//declarations
	vector <char> word;
	bool print_ay = false;
	//this puts a word into the vector word which is the only thing changed in a single loop
	while (phrase[place] != ' ')
	{
		word.push_back(phrase[place]);
		place++;
	}
	char temp;
	//this moves the vowels and stuff if necessary
	while (isVowel(word[0]) == false)
	{
		temp = word[0];
		word.push_back(temp);
		word.erase(word.begin());
		print_ay = true;
	}
	//puts on the correct ending
	if (print_ay == true)
	{
		word.push_back('a');
		word.push_back('y');
	}
	else
	{
		word.push_back('w');
		word.push_back('a');
		word.push_back('y');
	}
	//fix punctuation
	for (int i = 0; i < word.size(); i++)
	{
		if (ispunct(word.at(i)))
		{
			temp = word[i];
			word.push_back(temp);
			word.erase(word.begin() + i);
		}
	}
	
	//fix capitalization
	for (int h = 0; h < word.size(); h++)
	{
		if (isupper(word.at(h)))
		{
			word.at(h) = tolower(word.at(h));
			word.at(0) = toupper(word.at(0));
		}
	}
	//counting the letters and characters
	characters += word.size();
	for (int j = 0; j < word.size(); j++)
	{
		if (isalpha(word.at(j)))
			letters++;
	}
	printVector(word);
	cout << " ";
	place++;
}

bool isVowel(char letter)
{
	if (letter == 'A' || letter == 'I' || letter == 'E' || letter == 'O' || letter == 'U')
		return true;
	if (letter == 'a' || letter == 'i' || letter == 'e' || letter == 'o' || letter == 'u')
		return true;
	else
		return false;
}

void fillVector(vector<char>& v, string fileName)
{
	ifstream fin;
	fin.open(fileName);
	if (fin.fail())
	{
		cout << "name is not valid";
		return;
	}

	char temp;

	while (fin.get(temp))
	{
		v.push_back(temp);
	}
}

void printVector(vector<char> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v.at(i);
}