// MIT License
// 
// Copyright (c) 2024 Kristhel Quesada
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


/*
Tarea 3
Estudiante: Kristhel Quesada, C06153
Algoritmo: Creacion de una app de contactos donde los estos seran guardados
tanto en un espacio de "memoria" como en un "cloud", implementando el uso de
memoria dinamica.
*/

// Includes de los archivos y librerias necesarias
#include <iostream>
#include <string>
#include <cstdlib>
#include "Funciones.hpp"
#include "LinkedListFuncs.hpp"
using namespace std;


// ENUM para organizar el switch-case implementado en el menu
enum opciones {
    ADD_CONTACT = 1,
    DELETE_CONTACT,
    SHOW_CLOUD,
    SHOW_CONTACTS,
    SALIR,
    OPCIONES_MAX // para saber cuantas opciones tenemos
};


// MAIN FUNCTION
int main() {
    // Declaracion e inicializacion de variables
    Contacto* cloudList = nullptr; // lista enlazada para el Cloud
    Contacto* memoryList = nullptr; ; // lista enlazada para la memoria
    Contacto* ptrToDelete;
    Hashtable cloud;

    int phone_input, opcion, opcion2;
    string input, input2, name_input;

    bool detener = false; // bandera de detenimiento




    cout << "INICIO DEL PROGRAMA" << endl;
    // Loop para mantener la ejecucion del juego
    while (detener == false) {
        // Menu para el ususario
        cout << "\n______________________________________\n";
        cout << "MENU:\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Eliminar contacto\n";
        cout << "3. Imprimir informacion en el cloud\n";
        cout << "4. Mostrar todos los contactos\n";
        cout << "5. Salir del programa\n";
        cout << "\nQue desea realizar: ";
        cin >> input;
        opcion = verifyMenuOption(input, OPCIONES_MAX); // Maneja errores
        cin.ignore();


        // Determinacion de funcion a ejecutar
        switch (opcion) {
            case ADD_CONTACT:
                cout << "\nAGREAGANDO CONTACTO..." << endl;

                // Usuario ingresa datos del contacto
                cout << "Ingrese el nombre del nuevo contacto: ";
                getline(cin, name_input);
                cout << "Ingrese el numero del nuevo contacto: ";
                cin >> phone_input;

                // Agregar a memoria y al cloud
                addToMemory(name_input, phone_input, memoryList);
                addToCloud(name_input, phone_input, cloudList, cloud);


                break;

            case DELETE_CONTACT:
                cout << "\nELIMINANDO CONTACTO... " << endl;

                cout << "Ingrese el nombre del contacto que desea eliminar: ";
                getline(cin, name_input);

                cout << "\nDesea eliminar el contacto de: " << endl;
                cout << "1. La memoria" << endl;
                cout << "2. El cloud" << endl;
                cout << "3. Ambas" << endl;
                cout << "Escriba su respuesta: ";
                cin >> input2;
                opcion2 = verifyMenuOption(input2, 4); // Maneja errores

                switch (opcion2) {
                    case 1:
                        // Borra en la memoria only
                        deleteFromMemory(name_input, memoryList);
                        break;

                    case 2:
                        // Borra en el cloud only
                        ptrToDelete = cloud.deleteItem(name_input);
                        deleteFromCloud(name_input, cloudList, ptrToDelete);
                        break;

                    case 3:
                        // Borra en la memoria
                        deleteFromMemory(name_input, memoryList);

                        // Borra en el cloud
                        ptrToDelete = cloud.deleteItem(name_input);
                        deleteFromCloud(name_input, cloudList, ptrToDelete);
                        break;

                    default:
                        cout << "Opcion ingresada no valida." << endl;
                        break;
                }
                break;

            case SHOW_CLOUD:
                cout << "\nALMACENAMIENTO Y CLOUD... " << endl;
                showCloudList(cloudList);
                cout << "\n----------Tabla Hash----------\n";
                cloud.displayHash();
                cout << "--------------------------------\n";
                break;

            case SHOW_CONTACTS:
                cout << "\nLISTA DE CONTACTOS... " << endl;
                showMemoryList(memoryList);
                break;

            case SALIR:
                cout << "Gracias por utilizar el programa." << endl;
                detener = true;
                break;

            default:
                cout << "Opcion ingresada no valida." << endl;
                break;
        }
        
    }
    // Liberar la memoria de las listas
    freeCloudData(cloudList);
    cloud.freeHashTable();
    freeMemoryData(memoryList);

    return 0;
}