#include <iostream>
#include <fstream>

using namespace std;

void getNewPhrase(string& phrase)
{
    cout << "(Si quiere terminar ingrese 'fin')" << endl;
    cout << "Ingrese una frase:";
    getline(cin,phrase);
}

void savePhrase(string phrase, ofstream& archive)
{
    if(phrase != "fin")
    {
        archive << phrase << endl;
    }
}

void showLine(string phrase, int words)
{
    cout << phrase << endl;
    cout << "La frase contiene " << words << " palabras" << endl;
    cout << "------------------------------------------" << endl;
}

int calculateWordsPhraseNumber(string phrase)
{
    int words = 0;
    int i = 1;

    if(isalpha(phrase[0])) words ++;

    while( i < phrase.length())
    {
        if(phrase[i-1] == ' ' && isalpha(phrase[i])) words ++;
        i++;
    }
    return words;
}

string getWord(string phrase, int index)
{
    int item = index;
    string word = "";
    while(isalpha(phrase[item]))
    {
        word = word + phrase[item];
        item++;
    }

    return word;
}

void findLongWordOfPhrase(string phrase, string& longWord)
{
    string word = "";
    int i = 1;

    if(isalpha(phrase[0]))
    {
        word = getWord(phrase, 0);
        if( word > longWord) longWord = word;
    }
    while( i < phrase.length())
    {
        if(phrase[i-1] == ' ' && isalpha(phrase[i]))
        {
            word = getWord(phrase, i);
            if( word.length() > longWord.length()) longWord = word;
        }
        i++;
    }

}

void showFileData(int wordsNumber, int phrasesNumber, string longWord)
{
    cout << "hay " << wordsNumber << " palabras" << endl;
    cout << "el promedio por linea es de " << wordsNumber / phrasesNumber << " palabras" << endl;
    cout << "la palabra mas larga es " << longWord << endl;
}

int executeActionFileData(ifstream& fileToRead, string& phrase, string FILE_NAME)
{
    int phrasesNumber = 0;
    string word;
    int wordsNumber = 0;
    string longWord = "";

    fileToRead.open(FILE_NAME);

    if(fileToRead.is_open())
    {
        getline(fileToRead, phrase);
        while(phrase != "")
        {
            findLongWordOfPhrase(phrase, longWord);
            wordsNumber = wordsNumber + calculateWordsPhraseNumber(phrase);
            phrasesNumber++;
            getline(fileToRead, phrase);
        }
        fileToRead.close();

        showFileData(wordsNumber, phrasesNumber, longWord);
    }
    else
    {
        cout << "El archivo no se pudo abrir :(" << endl;
    }

}

void executeActionWrite(string& phrase, ofstream& fileToWrite, string FILE_NAME)
{
    fileToWrite.open(FILE_NAME);

    while (phrase != "fin")
    {
        getNewPhrase(phrase);
        savePhrase(phrase, fileToWrite);
    }
    fileToWrite.close();
    cout << "Archivo cerrado !" << endl;
    cout << "------------------------------------------" << endl;
}


void executeActionRead(string& phrase, ifstream& fileToRead, string FILE_NAME)
{
    fileToRead.open(FILE_NAME);
    cout << "++++ Mostrando lineas del archivo ++++" << endl;
    cout << "------------------------------------------" << endl;

    if(fileToRead.is_open())
    {
        getline(fileToRead, phrase);
        while(phrase != "")
        {
            showLine(phrase, calculateWordsPhraseNumber(phrase));
            getline(fileToRead, phrase);
        }
        fileToRead.close();
    }
    else
    {
        cout << "El archivo no se pudo abrir :(" << endl;
    }
}

int main()
{
    const string FILE_NAME = "frasesDeBjarme.txt";
    string phrase;
    ofstream fileToWrite;
    ifstream fileToRead;

    executeActionWrite(phrase, fileToWrite, FILE_NAME);

    executeActionRead(phrase, fileToRead, FILE_NAME);

    executeActionFileData(fileToRead, phrase, FILE_NAME);

    return 0;
}
