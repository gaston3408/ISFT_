// Marco Practico:
// Desarrollar un Programa que mantenga una lista de los estudiantes de Algoritmos y
// Estructuras de Datos I.
// Se deberán tener en cuenta las siguientes particularidades:
// a. De cada estudiante: nombre, apellidos, edad, DNI y nota
// b. Se desconoce el número total de estudiantes (máximo 50)
// c. La información de la lista se mantiene en un archivo AyEDI.txt
// d. Se carga el Archivo en Memoria llenando la Estructura al empezar y se guarda la
// estructura al finalizar el Programa en el mismo Archivo sobrescribiéndolo..
// El programa debe ofrecer estas opciones:
// e. Añadir un nuevo alumno
// f. Eliminar un alumno existente
// g. Calificar a los estudiantes
// h. Listado de notas, identificando la mayor y la media

#include <iostream>
#include <fstream>

using namespace std;


const int MAX = 50;
const string NAME_FILE = "NOTES.txt";
const string NAME_FILE_TEMP = "NOTES_TEMP.txt";
const string MESSAGE_ERROR = "No se pudo abrir el archivo";

struct Estudent {
  string name;
  string surname;
  int DNI;
  int note;
};

struct Data{
  Estudent estudents[MAX];
  int amount;
};

enum Action {
  CREATE,
  SHOW,
  REMOVE,
  UPDATE,
  EXIT
};

Data data;
ifstream file;
ofstream fileTemp;

ifstream openFile(string NAME_FILE);
ofstream openFileTemp(string NAME_FILE_TEMP);
void getData();
void showMenu();
int getOptionSelected();
void handleAction(Action action);
int getPosition();
int getNewNote();
void createNewEstudent();
void showEstudents();
void removeEstudent();
void updateEstudent();
void saveFile();

int main() {
  Action action;

  file = openFile(NAME_FILE);
  fileTemp = openFileTemp(NAME_FILE_TEMP);
  getData();
  showMenu();

  while(action != EXIT){
  cout << "Selecciona una opcion : ";
  action = Action(getOptionSelected());
  handleAction(action);
  }


  return 0;
}

void showMenu(){
  cout << "++++ BIENVENIDO ++++" << endl;
  cout << "**********************" << endl;
  cout << "MENU" << endl;
  cout << "1 - AGREGAR NUEVO ESTUDIANTE" << endl;
  cout << "2 - VER ESTUDIANTES" << endl;
  cout << "3 - ELIMINAR ESTUDIANTE" << endl;
  cout << "4 - CALIFICAR ESTUDIANTE" << endl;
  cout << "5 - SALIR" << endl;
  cout << "**********************" << endl;

}

int getOptionSelected(){
  int option;
  cin >> option;
  return option - 1;
}

ifstream openFile(string NAME_FILE){
  ifstream file;
  file.open(NAME_FILE);
  return file;
}

void validateFileTemp(ofstream &file){
  if(!file.is_open()){
    cout << MESSAGE_ERROR;
    exit(0);
  }
}

ofstream openFileTemp(string NAME_FILE_TEMP){
  ofstream file;
  file.open(NAME_FILE_TEMP);
  validateFileTemp(file);
  return file;
}

void getData(){

  data.amount = 0;
  while(file.is_open() && !file.eof()){
    file >> data.estudents[data.amount].name;
    file >> data.estudents[data.amount].surname;
    file >> data.estudents[data.amount].DNI;
    file >> data.estudents[data.amount].note;
    data.amount ++;
  }
  file.close();
}

int getPosition(){
  int position;
  cout << "Selecciona un estudiante por su numero (Para volver marca 0): ";
  cin >> position;
  return position;
}

int getNewNote(){
  int note;
  cout << "Introduce la nota: ";
  cin >> note;
  return note;
}

void createNewEstudent(){
  
  cout << "Nombre: ";
  cin >> data.estudents[data.amount].name;
  cout << "Apellido: ";
  cin >> data.estudents[data.amount].surname;
  cout << "DNI: ";
  cin >> data.estudents[data.amount].DNI;
  data.estudents[data.amount].note= 0;
  data.amount++;

  cout << "****************************" << endl;
  cout << "Estudiante registrado correctamente !!" << endl;
  cout << "****************************" << endl;
}

void showEstudents(){
    cout << "***********************" << endl;
  for(int i=0; i < data.amount; i++){
    cout << i + 1 
    << " - " << data.estudents[i].name 
    << " " << data.estudents[i].surname 
    << " - DNI: " << data.estudents[i].DNI
    << " - Calificacion: " << data.estudents[i].note << endl;
  }
  cout << "***********************" << endl;
}

void removeEstudent(){
  int position = getPosition();
  
  if(position > 0){
    for(int i = position - 1; i < data.amount; i++){
        data.estudents[i] = data.estudents[i + 1];
    }
    data.amount --;
  }
}

void updateEstudent(){
  int position = getPosition();

  if(position > 0){
    int newNote = getNewNote();
    data.estudents[position - 1].note = newNote;
    cout << "***********************" << endl;
    cout << "Calificación actualizada con éxito !!" << endl;
    cout << "***********************" << endl;
  }
}

void saveFile(){
  for(int i = 0; i < data.amount; i++){
    fileTemp << data.estudents[i].name;
    fileTemp << " ";
    fileTemp << data.estudents[i].surname;
    fileTemp << " ";
    fileTemp << data.estudents[i].DNI;
    fileTemp << " ";
    fileTemp << data.estudents[i].note;
  }
  fileTemp.close();
  remove("NOTES.txt");  
  rename("NOTES_TEMP.txt", "NOTES.txt");
}

void handleAction(Action action){

    switch(action){
      case CREATE:
        createNewEstudent();
        break;
      case SHOW:
        showEstudents();
        break;
      case REMOVE:
        removeEstudent();
        break;
      case UPDATE:
        updateEstudent();
        break;
      case EXIT:
        saveFile();
        break;
      default:
        cout << "No es una opción válida" << endl;
        break;

  }
}
