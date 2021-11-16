#include <iostream>
#include "./Entities/ListStudents.hpp"
using namespace std;

int main()
{
    Student betterStudent;
    ListStudents list;
    getStudents(&list);
    betterStudent = getBetterStudent(list);

    cout << "El estudiante con mejor promedio es : " << betterStudent.name << endl;
    cout << "Con " << betterStudent.yearsOld << "de edad" << endl;
    cout << "Con un promedio de " << betterStudent.average << endl;

    deleteStudents(list);

    return 0;
}

