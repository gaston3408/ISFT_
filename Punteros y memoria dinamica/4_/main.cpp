
#include <iostream>

using namespace std;

void getPhrase(char *phrase, int size);
void countVocal(char *phrase, int size);

int main()
{
    char phrase[200];

    getPhrase( phrase, 200 );
    countVocal( phrase, 200 );

    return 0;
}

void getPhrase(char *phrase, int size){

    cout << "Ingrese frase: ";
    cin.getline( phrase, size, '\n');
}

void countVocal(char *phrase, int size){

    int a = 0;
    int e = 0;
    int i = 0;
    int o = 0;
    int u = 0;

    for (int i = 0; i < size; i++)
    {
        switch (phrase[i])
        {
        case 'a': a++;
            break;
        case 'e': e++;
            break;
        case 'i': i++;
            break;
        case 'o': o++;
            break;
        case 'u': u++;
            break;
        default:
            break;
        }
    }

    cout << "Hay " << a << " letras a" << endl;
    cout << "Hay " << e << " letras e" << endl;
    cout << "Hay " << i << " letras i" << endl;
    cout << "Hay " << o << " letras o" << endl;
    cout << "Hay " << u << " letras u" << endl;
    
}