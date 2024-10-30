///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Instrucciones y contenido agregado

// terminar consultar

// agreguen modificar y borrar

// Validaciones cuando se busca un usuario y no existe

// Agregar telefono, direccion 

// validación al ingresar estudiantes en la cantidad máxima en el arreglo

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Variables globales.

char nombre[3][50];
float notas[3];
char telefono[3][30];
char direccion[3][60];
int indice = 0;
char nombreBusqueda[50];  

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void consultar() {
    bool encontrado = false;

    cout << "Digite el nombre del estudiante: ";
    cin >> nombreBusqueda;

    for (int i = 0; i < indice; i++) {
        if (strcmp(nombre[i], nombreBusqueda) == 0) {
        	
            cout << "Nombre: " << nombre[i] << "\n";
            cout << "Nota: " << notas[i] << "\n";
            cout << "Telefono: " << telefono[i] << "\n";
            cout << "Direccion: " << direccion[i] << "\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Estudiante no encontrado.\n";
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ingresar() {
	
    char seguir;

    do {
        if (indice >= 3) {
            cout << "Limite máximo de estudiantes alcanzado.\n";
            break;
        }

        cout << "Digite el nombre: ";
        cin >> nombre[indice];

        cout << "Digite la nota: ";
        cin >> notas[indice];

        cout << "Ingrese su numero de telefono: ";
        cin >> telefono[indice];

        cout << "Ingrese su direccion: ";
        cin >> direccion[indice];

        cout << "Desea continuar (s/n): ";
        cin >> seguir;

        indice++;

    } while (seguir == 's' || seguir == 'S');
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void reporte() {
    cout << "\nNombre            Nota          Telefono           Direccion\n";
    cout << "--------------------------------------------------------------\n";
    for (int i = 0; i < indice; i++) {
    	
        cout << nombre[i] << "        " << notas[i] << "        " << telefono[i] << "        " << direccion[i] << "\n";
        
    }
    cout << "\n";
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modificar() {
    bool encontrado = false;

    cout << "Digite el nombre del estudiante a modificar: ";
    cin >> nombreBusqueda;

    for (int i = 0; i < indice; i++) {
        if (strcmp(nombre[i], nombreBusqueda) == 0) {
            cout << "Digite el nuevo nombre: ";
            cin >> nombre[i];
            cout << "Digite la nueva nota: ";
            cin >> notas[i];
            cout << "Ingrese el nuevo numero de telefono: ";
            cin >> telefono[i];
            cout << "Ingrese la nueva direccion: ";
            cin >> direccion[i];
            cout << "Registro modificado correctamente.\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Estudiante no encontrado.\n";
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void borrar() {
    bool encontrado = false;

    cout << "Digite el nombre del estudiante a borrar: ";
    cin >> nombreBusqueda;

    for (int i = 0; i < indice; i++) {
        if (strcmp(nombre[i], nombreBusqueda) == 0) {
            for (int j = i; j < indice - 1; j++) {
                strcpy(nombre[j], nombre[j + 1]);
                notas[j] = notas[j + 1];
                strcpy(telefono[j], telefono[j + 1]);
                strcpy(direccion[j], direccion[j + 1]);
            }
            indice--;
            cout << "Estudiante borrado correctamente.\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Estudiante no encontrado.\n";
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menu() {
    char seguir = 's';
    int opcion = 0;

    do {
        cout << "\n";
        cout << "1- Ingresar Estudiantes\n";
        cout << "2- Consultar Estudiantes\n";
        cout << "3- Reporte Estudiantes\n";
        cout << "4- Modificar Estudiante\n";
        cout << "5- Borrar Estudiante\n";
        cout << "6- Salir\n";
        cout << "Digite una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: ingresar(); break;
            case 2: consultar(); break;
            case 3: reporte(); break;
            case 4: modificar(); break;
            case 5: borrar(); break;
            case 6: cout << "Saliendo del programa...\n"; seguir = 'n'; break;
            default: cout << "Opcion no valida. Intente de nuevo con una opción válida, por favor.\n"; break;
        }

    } while (seguir == 's' || seguir == 'S');
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    menu();
    return 0;
}
