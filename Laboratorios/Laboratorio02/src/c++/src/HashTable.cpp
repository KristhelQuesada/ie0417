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

#include "HashTable.hpp"
#include <iostream>
#include <string>
using namespace std;

/*
IMPLEMENTACION DE LAS FUNCIONES DE "HashTable.hpp"
*/

// Constructor
Hashtable::Hashtable() {
    // Inicializa la tabla con structs Nodo* para cada bucket
    for (int i=0; i < MAX_ELEMENTS; i++) {
        Nodo* initialNode = nullptr;
        tablaHash[i] = initialNode;
    }
}



// Hash Function
int Hashtable::hashFunction(string key) {
    unsigned long hashValue = 0;
    
    // Se recorre cada caracter del string
    for (char crctr : key) {
      hashValue += crctr; // suma el valor ASCII proporcional al hashValue
    }

    // Retorna un valor entero entre el tamanio del hashtable
    return (hashValue % MAX_ELEMENTS);
}



// Funcion para agregar un item a la HashTable
void Hashtable::insertItem(string key, Contacto* value) {
    int hashIndex = hashFunction(key); // determinar el indice para el key
    Nodo* &initialNode = tablaHash[hashIndex];

    // Caso 1. El bucket esta vacio
    if (initialNode == nullptr) {
        Nodo* newNode = new Nodo;
        initialNode = newNode;
        initialNode->ptrContactValue = value;
        initialNode->siguiente = nullptr;

        // Caso 2. El bucket contiene uno o mas elementos
    } else {
        // Se inicializan los nodos
        Nodo* currentNode = initialNode;
        Nodo* nextNode = initialNode->siguiente;

        // Hasta que nextNode sea nullptr
        while (nextNode != nullptr) {
            currentNode = nextNode;
            nextNode = currentNode->siguiente;
        }

        // Si nextNode es nullptr entonces significa que llegamos
        // al ultimo bucket por tanto
        Nodo* newNode = new Nodo; // creamos un nuevo nodo
        nextNode = newNode; // le asignamos esa direccion a nextNode

        // Luego vinculamos el nuevo nodo al currentNode
        currentNode->siguiente = nextNode;

        // Finalmente, le asignamos su valor
        nextNode->ptrContactValue = value; // le asignamos su value
        nextNode->siguiente = nullptr; // decimos que despues de el no hay nada
    }
}



// Funcion para visualizar el HashTable by far
void Hashtable::displayHash() {
    // Recorre cada bucket
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        cout << "Bucket[" << i << "] ";

        // Inicializa los Nodos para recorrer el bucket
        Nodo* currentNode = tablaHash[i];

        // Verifica si el nodo esta vacio
        if (currentNode == nullptr) {
            cout << endl;
            continue; // salte al siguiente bucket/iteracion
        }

        // Nodo no vacio por tanto para cada Nodo* con el mismo indice
        while (currentNode != nullptr) {
            Contacto* contacto = currentNode->ptrContactValue;
            cout << "--> " << contacto->name;
            currentNode = currentNode->siguiente; // Avanza al siguiente nodo
        }
        cout << endl;
    }
}



// Funcion para liberar la memoria utilizada por la HashTable
void Hashtable::freeHashTable() {
    // Recorre cada bucket
    for (int i = 0; i < MAX_ELEMENTS; i++) {

        // Inicializa nodo para recorrer el bucket
        Nodo* currentNode = tablaHash[i];

        // Verifica si el bucket actual está vacío
        if (currentNode == nullptr) {
            continue; // Pasar al siguiente bucket/iteracion
        }

        // Nodo no vacio por tanto para cada Nodo* con el mismo indice
        while (currentNode != nullptr) {
            Nodo* nodeToDelete = currentNode; // se guarda el puntero en un nodo auxiliar/temp
            currentNode = currentNode->siguiente; // se actualiza el primer nodo como el segundo
            delete nodeToDelete; // se libera el original primer nodo
        }

        // Actualiza el bucket como vacio nuevamente
        tablaHash[i] = nullptr;
    }
}



Contacto* Hashtable::deleteItem(string key) {
    // Recorre cada bucker
    for (int i = 0; i < MAX_ELEMENTS; i++) {

        // Inicializa nodos para recorrer el bucket
        Nodo* currentNode = tablaHash[i];
        Nodo* previousNode = nullptr;

        // Siempre que el bucket no este vacio entonces para cada nodo con el mismo key
        while (currentNode != nullptr) {

            // Se inspecciona su contenido
            Contacto* ptrContacto = currentNode->ptrContactValue;

            // Si el nombre del contacto del actual nodo es igual al key
            if (ptrContacto->name == key) {

                // Seleccione ese nodo para eliminarlo
                Nodo* nodeToDelete = currentNode;

                // Si ese nodo era el primero del bucker
                if (previousNode == nullptr) {
                    tablaHash[i] = currentNode->siguiente; // actualice su nuevo primero
                } else {
                    previousNode->siguiente = currentNode->siguiente; // si no, reorganice
                }

                // Luego se extrae el valor que contenia el nodo a eliminar
                Contacto* contactToReturn = nodeToDelete->ptrContactValue;
                delete nodeToDelete; // se elimina el nodo
                return contactToReturn; // se retorna el valor


            } else {
                // si el nombre del contacto no era igua a la llave
                // entonces siga buscando mediante el analisis del
                // siguiente nodo
                previousNode = currentNode;
                currentNode = currentNode->siguiente;
            }
        }
    }
    return nullptr; // El elemento no se encontró en el hash table
}