//#include <iostream>
//#include "Massive.h"
//#include "Massive.cpp"

//#include "Employer.h"
//using namespace std;
//
//int main()
//{
//	Employer** employers = new Employer * [3];
//	employers[0] = new President("John", 52);
//	employers[1] = new Manager("Garry", 46);
//	employers[2] = new Worker("Ted", 38);
//	for (int i = 0; i < 3; i++)
//	{
//		employers[i]->Print();
//	}
//}

//int main()
//{
//	try
//	{
//		ArrayTemp<int> myMass(5);
//		cout << myMass << endl;
//		myMass.Insert(1, 5);
//		cout << myMass << endl;
//		myMass.Remove(3);
//		cout << myMass << endl;
//	}
//	catch (exception& exp)
//	{
//		cout << exp.what() << endl;
//	}
//}

//#include <iostream>
//#include <windows.h>
//#include <io.h>
//#include <stdio.h>
//using namespace std;
//
//wchar_t* convertCharArrayToLPCWSTR(const char* charArray)
//{
//	wchar_t* wString = new wchar_t[4096];
//	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
//	return wString;
//}
//
//void RussianMessage(const char* str) 
//{
//	char message[100];
//	convertCharArrayToLPCWSTR(str);
//	CharToOem(convertCharArrayToLPCWSTR(str), message);
//	cout << message;
//}
//
//bool CopyFile(const char* source, const char* destination) 
//{
//	const int size = 65536;
//	FILE* src, * dest;
//	if (!(src = fopen(source, "r"))) 
//	{
//		throw exception("No files");
//	}
//	int handle = _fileno(src);
//	char* data = new char[size];
//	if (!data) {
//		return false;
//	}
//	if (!(dest = fopen(destination, "w"))) 
//	{
//		delete[]data;
//		return false;
//	}
//	int realsize;
//	while (!feof(src)) 
//	{
//		realsize = fread(data, sizeof(char), size, src);
//		fwrite(data, sizeof(char), realsize, dest);
//	}
//	fclose(src);
//	fclose(dest);
//	return true;
//}
//
//void main() 
//{
//	char source[_MAX_PATH];
//	char destination[_MAX_PATH];
//	char answer[20];
//	RussianMessage("\nВведите путь и название копируемого файлу :\n");
//	cin.getline(source, _MAX_PATH);
//	if (_access(source, 00) == -1) 
//	{
//		RussianMessage("\nУказан неверный путь или название файла\n");
//			return;
//	}
//	RussianMessage("\nВведите путь и название нового файла:\n");
//	cin.getline(destination, _MAX_PATH);
//	if (_access(destination, 00) == 0) 
//	{
//		RussianMessage("\nТакой Файл уже существует перезаписать его(1 - Да / 2 - Нет) ? \n");
//		cin.getline(answer, 20);
//		if (!strcmp(answer, "2")) 
//		{
//			RussianMessage("\nОперация отменена\n");
//			return;
//		}
//		else if (strcmp(answer, "1")) 
//		{
//			RussianMessage("\nНеправильный ввод\n");
//			return;
//		}
//		if (_access(destination, 02) == -1) 
//		{
//			RussianMessage("\nНет доступа к записи.\n");
//			return;
//		}
//	}
//
//	/*if (!CopyFile(source, destination)) {
//		RussianMessage("\nОшибка при работе с файлом\n");
//	}
//
//	const char* source = "test_from.txt";
//	const char* destination = "test_to.txt";
//
//	try
//	{
//		CopyFile(source, destination);
//	}
//	catch (exception& exp)
//	{
//		cout << "Error in CopyFile -> " << exp.what() << endl;
//	}*/
//}

#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <ctime>
#include <sys\locking.h>
#include <string.h>
#include <ctype.h>
using namespace std;

#define MAX_WORD_LENGTH 21
int Tries = 10;
int CountWords = 0;

bool LoadWord(FILE* file, char* word)
{
	int i = 0;
	char s[MAX_WORD_LENGTH] = { 0 };
	static int count = -1;
	if (count == -1)
	{
		while (!feof(file))
		{
			fgets(s, MAX_WORD_LENGTH, file);
			count++;
		}
		if (count == 0)
			return false;
		fseek(file, 0, 0);
	}

	int n = rand() % count;
	while (i <= n)
	{
		fgets(s, MAX_WORD_LENGTH, file);
		i++;
	}
	int wordlen = strlen(s);
	if (wordlen <= 1)
		return false;
	if (s[wordlen - 1] == 10)
		s[wordlen - 2] = 0;
	else if (s[wordlen - 1] == 13)
		s[wordlen - 1] = 0;
	strcpy(word, s);
	int hFile = _fileno(file);
	int size = _filelength(hFile);
	fseek(file, 0, 0);
	_locking(hFile, _LK_NBLCK, size);
	return true;
}
void Game(char* word)
{
	strupr(word);
	int len = strlen(word);
	char* copy = new char[len + 1];
	memset(copy, '*', len);
	copy[len] = 0;
	char letters[52];
	int i, j = 0;
	for (i = 0; i < 26; i++)
	{
		letters[j++] = i + 'A';
		letters[j++] = ' ';
	}
	letters[51] = 0;
	char letter;
	char* pos;
	bool replace = false;
	do {
		system("cls");
		cout << copy << endl << endl;
		cout << letters << endl << endl;
		cout << "Count of tries: " << Tries << endl
			<< endl;
		cout << "Input any letter:\t";
		cin >> letter;
		if (!isalpha(letter))
		{
			cout << "It's not a letter" << endl;
			Sleep(1000);
			continue;
		}
		letter = toupper(letter);
		pos = strchr(letters, letter);

		if (pos == 0)
		{
			cout << "This letter have been already pressed" << endl;
				Sleep(1000);
			continue;
		}
		else
		{
			pos[0] = ' ';
		}
		for (i = 0; i < len; i++)
		{
			if (word[i] == letter)
			{
				copy[i] = letter;
				replace = true;
			}
		}
		if (replace == false)
			Tries--;
		else
			replace = false;
		if (strcmp(word, copy) == 0)
		{
			system("cls");
			cout << copy << endl << endl;
			cout << letters << endl << endl;
			cout << "Count of tries: " << Tries <<
				endl << endl;
			cout << "Congratulation !!!" << endl;
			CountWords++;
			break;
		}
	} while (Tries != 0);
	delete[] copy;
}
void main()
{
	FILE* f = fopen("words.txt", "rb");
	if (f == 0)
	{
		perror("Open");
		return;
	}
	srand(time(NULL));
	char Word[20];
	if (!LoadWord(f, Word))
	{
		cout << "Error !!!" << endl;
		fclose(f);
		return;
	}
	char answer;
	do
	{
		Game(Word);
		if (Tries == 0)
		{
			cout << "Count of words: " << CountWords << endl;
			cout << "Bye-bye" << endl;
			break;
		}
		cout << "Continue ??? (Y/N)\t";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
			if (!LoadWord(f, Word))
			{
				cout << "Error !!!" << endl;
				fclose(f);
				return;
			}
	} 
	while (answer == 'Y' || answer == 'y');
	int hFile = _fileno(f);
	int size = _filelength(hFile);
	fseek(f, 0, 0);
	_locking(hFile, _LK_UNLCK, size);
	fclose(f);
}

