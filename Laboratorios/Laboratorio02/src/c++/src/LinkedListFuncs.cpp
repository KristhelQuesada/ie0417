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

#include <iostream>
#include <string>
#include "LinkedListFuncs.hpp"
using namespace std;

/*
------------------------------------------------------------------
FUNCIONES PARA LA LISTA ENLAZADA DEL CLOUD
*/
void addToCloud(string nombre, int numero, Contacto*& lista, Hashtable& hashTable) {
    Contacto* contactCopy = new Contacto;
    contactCopy->name.assign(nombre);
    contactCopy->phone = numero;
    contactCopy->siguiente = lista;
    lista = contactCopy;

    cout << "Contacto agregado correctamente al Cloud" << endl;
    
    // Implementacion de agregar contacto al hash pendiente aca
    // agregue codigo aca
    hashTable.insertItem(nombre, contactCopy);

}



void showCloudList(Contacto* lista) {
    int i; // lleva la cuenta de los contactos

    // Verifica que la lista esta vacia
    if (lista == nullptr) {
        cout << "La agenda no tiene contactos" << endl;

        return; // para evitar ejecutar el while y cout cuando se cumple esta condicion
    }

    // Imprime la lista
    while (lista != nullptr) {
        i++;
        cout << ">> Contacto " << i << ": ";
        cout << lista->name << ", Tel. ";
        cout << lista->phone << endl;

        lista = lista->siguiente;
    }
}



void freeCloudData(Contacto*& lista) {
    while (lista != nullptr) {
        Contacto* temp = lista;
        lista = lista->siguiente;
        delete temp;
    }
}



void deleteFromCloud(string nombre, Contacto*& lista, Contacto* ptrContacto) {
    if (ptrContacto == nullptr) {
        cout << "Contacto '" << nombre << "' no existe en el Cloud." << endl;
        return;
    }

    // Verificar si el primer elemento de la lista es el que queremos eliminar
    if (lista == ptrContacto) {
        lista = lista->siguiente;
        delete ptrContacto;
        cout << "Contacto '" << nombre << "' ha sido eliminado." << endl;
        return;
    }

    Contacto* currentContact = lista;
    Contacto* previousContact = nullptr;

    // Buscar ptrContacto en la lista
    while (currentContact != nullptr) {
        if (currentContact == ptrContacto) {
            previousContact->siguiente = currentContact->siguiente;
            delete currentContact;
            cout << "Contacto '" << nombre << "' ha sido eliminado." << endl;
            return;
        }
        previousContact = currentContact;
        currentContact = currentContact->siguiente;
    }

    cout << "Contacto '" << nombre << "' no existe en la lista." << endl;
}



/*
------------------------------------------------------------------
FUNCIONES PARA LA LISTA ENLAZADA DE LA MEMORIA
*/
void addToMemory(string nombre, int numero, Contacto*& lista) {
    Contacto* contactCopy = new Contacto;
    contactCopy->name.assign(nombre);
    contactCopy->phone = numero;
    contactCopy->siguiente = lista;
    lista = contactCopy;

    cout << "Contacto agregado correctamente a la memoria" << endl;

}



void showMemoryList(Contacto* lista) {
    int i; // lleva la cuenta de los contactos

    // Verifica que la lista esta vacia
    if (lista == nullptr) {
        cout << "La agenda no tiene contactos" << endl;

        return; // para evitar ejecutar el while y cout cuando se cumple esta condicion
    }

    // Imprime la lista
    while (lista != nullptr) {
        i++;
        cout << ">> Contacto " << i << endl;
        cout << "Nombre: " << lista->name << endl;
        cout << "Telefono: " << lista->phone << endl << endl;

        lista = lista->siguiente;
    }
}



void freeMemoryData(Contacto*& lista) {
    while (lista != nullptr) {
        Contacto* temp = lista;
        lista = lista->siguiente;
        free(temp);
    }
}


void deleteFromMemory(string nombre, Contacto*& lista) {
    // Verifica si la lista está vacía inicialmente para evitar
    // iteraciones innecesarias
    if (lista == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }

    // Inicializa los punteros para recorrer la lista
    Contacto* currentContact = lista;
    Contacto* previousContact = nullptr;

    // Recorre la lista hasta que currentContact sea nulo, o sea, se llega al final
    while (currentContact != nullptr) {

        // Verifica si el contacto actual coincide con el nombre buscado
        if (currentContact->name == nombre) {

            // Si el contacto a eliminar es el primero de la lista
            if (previousContact == nullptr) {
                lista = currentContact->siguiente; // Lista ahora comienza en el siguiente contacto

            } else {
                /*
                El contacto previo ahora sera el contacto enlazado a 'siguiente' del
                currentContact, ya que este ultimo piensa eliminarse
                */
                previousContact->siguiente = currentContact->siguiente;
            }

            // Libera la memoria del contacto actual
            free(currentContact);
            cout << "Contacto '" << nombre << "' ha sido eliminado." << endl;
            return;
        }

        // Si no hubo match entonces avanza al siguiente contacto
        previousContact = currentContact;
        currentContact = currentContact->siguiente;
    }

    // Si se recorre todo la lista y no hubo match entonces
    cout << "No se encontró el contacto: " << nombre << endl;
}

