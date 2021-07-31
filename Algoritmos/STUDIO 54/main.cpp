
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int MAX = 100;
const string NAME_FILE = "STUDIO_FEST.txt";
const string NAME_FILE_TEMP = "STUDIO_FEST_TEMP.txt";
const string MESSAGE_ERROR = "No se pudo abrir el archivo";

struct Person
{
  int ticket;
  string name;
  string surname;
  int DNI;
  double tel;
  int assistance;
};

struct Data
{
  Person invited[MAX];
  int amount;

  void createNewInvited();
  void showInviteds();
  void showAssistants();
  void removeInvited();
  void updateAssistence();
  void updateInvited();
  void getData();
};

enum Action
{
  CREATE,
  SHOW,
  SHOW_ASSISTANT,
  UPDATE,
  UPDATE_ASSISTANCE,
  REMOVE,
  EXIT
};

Data data;
ifstream file;
ofstream fileTemp;

void showMenu();
int getOptionSelected();
void handleAction(Action action);
int getPosition();
double getTicketNumber();
int getNewNote();
ifstream openFile(string NAME_FILE);
ofstream openFileTemp(string NAME_FILE_TEMP);
void saveFile();

int main()
{
  Action action;

  file = openFile(NAME_FILE);
  fileTemp = openFileTemp(NAME_FILE_TEMP);
  data.getData();
  showMenu();

  while (action != EXIT)
  {
    cout << "Selecciona una opcion : ";
    action = Action(getOptionSelected());
    handleAction(action);
  }

  return 0;
}

void showMenu()
{
  cout << "++++ BIENVENIDO A STUDIO 54 ++++" << endl;
  cout << "**********************" << endl;
  cout << "MENU" << endl;
  cout << "1 - AGREGAR NUEVO INVITADO" << endl;
  cout << "2 - VER INVITADOS" << endl;
  cout << "3 - VER INVITADOS ASISTENTES" << endl;
  cout << "4 - ACTUALIZAR DATOS DEL INVITADO" << endl;
  cout << "5 - ACTUALIZAR ASISTENCIA" << endl;
  cout << "6 - ELIMINAR INVITADO" << endl;
  cout << "7 - SALIR" << endl;
  cout << "**********************" << endl;
}

int getOptionSelected()
{
  int option;
  cin >> option;
  return option - 1;
}

ifstream openFile(string NAME_FILE)
{
  ifstream file;
  file.open(NAME_FILE);
  return file;
}

void validateFileTemp(ofstream &file)
{
  if (!file.is_open())
  {
    cout << MESSAGE_ERROR;
    exit(0);
  }
}

ofstream openFileTemp(string NAME_FILE_TEMP)
{
  ofstream file;
  file.open(NAME_FILE_TEMP);
  validateFileTemp(file);
  return file;
}

void Data::getData()
{

  data.amount = 0;
  while (file.is_open() && !file.eof())
  {

    file >> data.invited[data.amount].ticket;
    file >> data.invited[data.amount].name;
    file >> data.invited[data.amount].surname;
    file >> data.invited[data.amount].DNI;
    file >> data.invited[data.amount].tel;
    file >> data.invited[data.amount].assistance;
    data.amount++;
  }
  file.close();
}

int getPosition()
{
  int position;
  cout << "Selecciona un invitado por su numero (Para volver marca 0): ";
  cin >> position;
  return position;
}

double getTicketNumber()
{
  double ticketNumber;
  cout << "Ingresa el número de ticket (Para volver marca 0): ";
  cin >> ticketNumber;
  return ticketNumber;
}

void Data::createNewInvited()
{
  srand(time(NULL));

  cout << "Nombre: ";
  cin >> data.invited[data.amount].name;
  cout << "Apellido: ";
  cin >> data.invited[data.amount].surname;
  cout << "DNI: ";
  cin >> data.invited[data.amount].DNI;
  cout << "tel: ";
  cin >> data.invited[data.amount].tel;
  data.invited[data.amount].assistance = false;
  data.invited[data.amount].ticket = rand();
  data.amount++;

  cout << "****************************" << endl;
  cout << "Invitado registrado correctamente !!" << endl;
  cout << "****************************" << endl;
}

void Data::showInviteds()
{
  cout << "***********************" << endl;
  cout << "FIESTA STUDIO 54" << endl;
  cout << "***********************" << endl;
  for (int i = 0; i < data.amount; i++)
  {
    cout << i + 1
         << " - " << data.invited[i].name
         << " " << data.invited[i].surname
         << " - DNI: " << data.invited[i].DNI
         << " - TICKET: " << data.invited[i].ticket
         << " - Asistencia: " << (data.invited[i].assistance ? "SI" : "NO") 
         << endl;
  }
  cout << "***********************" << endl;
}

void Data::showAssistants()
{
  cout << "***********************" << endl;
  cout << "INVITADOS ASISTENTES A STUDIO 54" << endl;
  cout << "***********************" << endl;
  for (int i = 0; i < data.amount; i++)
  {

    if (data.invited[i].assistance)
    {

      cout << i + 1
           << " - " << data.invited[i].name
           << " " << data.invited[i].surname
           << " - DNI: " << data.invited[i].DNI
           << " - TICKET: " << data.invited[i].ticket
           << endl;
    }
  }
  cout << "***********************" << endl;
}

void Data::removeInvited()
{
  int position = getPosition();

  if (position > 0)
  {
    for (int i = position - 1; i < data.amount; i++)
    {
      data.invited[i] = data.invited[i + 1];
    }
    data.amount--;
  }
}

void Data::updateAssistence()
{
  int ticketNumber = getTicketNumber();

  if (ticketNumber > 0)
  {
    for (int i = 0; i < data.amount; i++)
    {
      if(data.invited[i].ticket == ticketNumber){

        data.invited[i].assistance = !data.invited[i].assistance;
        cout << "***********************" << endl;
        cout << "Asistencia actualizada con éxito !!" << endl;
        cout << "***********************" << endl;
        return;
      }
    }
    cout << "***********************" << endl;
    cout << "No existe el ticket de invitado ingresado." << endl;
    cout << "***********************" << endl;
  }
}

void Data::updateInvited()
{
  int position = getPosition();

  cout << "Nombre: ";
  cin >> data.invited[position - 1].name;
  cout << "Apellido: ";
  cin >> data.invited[position - 1].surname;
  cout << "DNI: ";
  cin >> data.invited[position - 1].DNI;
  cout << "tel: ";
  cin >> data.invited[position - 1].tel;
  cout << "***********************" << endl;
  cout << "Invitado actualizado con éxito !!" << endl;
  cout << "***********************" << endl;
}

void saveFile()
{
  for (int i = 0; i < data.amount; i++)
  {
    fileTemp << data.invited[i].ticket;
    fileTemp << " ";
    fileTemp << data.invited[i].name;
    fileTemp << " ";
    fileTemp << data.invited[i].surname;
    fileTemp << " ";
    fileTemp << data.invited[i].DNI;
    fileTemp << " ";
    fileTemp << data.invited[i].tel;
    fileTemp << " ";
    fileTemp << data.invited[i].assistance;
  }
  fileTemp.close();
  remove("STUDIO_FEST.txt");
  rename("STUDIO_FEST_TEMP.txt", "STUDIO_FEST.txt");
}

void handleAction(Action action)
{

  switch (action)
  {
  case CREATE:
    data.createNewInvited();
    break;
  case SHOW:
    data.showInviteds();
    break;
  case SHOW_ASSISTANT:
    data.showAssistants();
    break;
  case REMOVE:
    data.removeInvited();
    break;
  case UPDATE_ASSISTANCE:
    data.updateAssistence();
    break;
  case UPDATE:
    data.updateInvited();
    break;
  case EXIT:
    saveFile();
    break;
  default:
    cout << "No es una opción válida" << endl;
    break;
  }
}
