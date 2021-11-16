#include "Student.hpp"
#include <iostream>
using namespace std;

typedef StudentP ArrayStudents[100];

typedef struct 
{
    ArrayStudents students;
    int count;

} ListStudents;

void getStudents( ListStudents *list ){
        int on = 1;
        list->count = 0;

         while (on == 1)
        {
            list->students[list->count] = new Student();
            cout << "+++ Ingresa estudiante +++" << endl;
            cout << "Ingresa su name: ";
            cin >> list->students[list->count]->name;
            cout << "Ingresa su edad: ";
            cin >> list->students[list->count]->yearsOld;
            cout << "Ingresa su promedio: ";
            cin >> list->students[list->count]->average;
            cout << "Desea ingresar uno mas ? (si = 1, no = 0) :";
            cin >> on;
            list->count++;
        }
        
    }

    Student getBetterStudent( ListStudents list){
        int betterAverage = 0;
        Student betterStudent; 
        for (int i = 0; i < list.count; i++)
        {

            if(list.students[i]->average > betterAverage)
            {
                betterAverage = list.students[i]->average;

                betterStudent.name = list.students[i]->name;
                betterStudent.yearsOld = list.students[i]->yearsOld;
                betterStudent.average = list.students[i]->average;
            }
        }
        return betterStudent;
    }

    void deleteStudents( ListStudents list){
        for (int i = 0; i < list.count; i++)
        {
            delete list.students[i];
        }
        
    }
