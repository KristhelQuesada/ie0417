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

#ifndef LINKEDLISTFUNCS_HPP
#define LINKEDLISTFUNCS_HPP

#include "Contacto.hpp"
#include "HashTable.hpp"

/**
 * @file LinkedListFuncs.hpp
 * @brief Funciones auxiliares para manejar listas enlazadas en el sistema Cloud y Memoria.
 */

/** 
 * @brief Agrega un contacto tanto a la lista enlazada del "Cloud" como al hash table.
 * 
 * @param nombre Nombre del contacto.
 * @param numero Número de teléfono del contacto.
 * @param lista Referencia al puntero de la lista enlazada.
 * @param hashTable Referencia a la tabla hash donde también se insertará el contacto.
 */
void addToCloud(std::string nombre, int numero, Contacto*& lista, Hashtable& hashTable);

/**
 * @brief Muestra toda la información almacenada en la lista enlazada del "Cloud".
 * 
 * @param lista Puntero al primer nodo de la lista enlazada.
 */
void showCloudList(Contacto* lista);

/**
 * @brief Libera la memoria dinámica asignada para la lista enlazada del "Cloud".
 * 
 * @param lista Referencia al puntero de la lista a liberar.
 */
void freeCloudData(Contacto*& lista);

/**
 * @brief Elimina un contacto específico del "Cloud".
 * 
 * @param nombre Nombre del contacto a eliminar.
 * @param lista Referencia al puntero de la lista enlazada.
 * @param ptrContacto Puntero al contacto que se desea eliminar.
 */
void deleteFromCloud(std::string nombre, Contacto*& lista, Contacto* ptrContacto);

// -----------------------------------------------------------------------

/**
 * @brief Agrega un contacto a la lista enlazada de "Memoria".
 * 
 * Aunque no se requiere una lista enlazada, se implementa de esta forma para mantener consistencia.
 *
 * @param nombre Nombre del contacto.
 * @param numero Número de teléfono del contacto.
 * @param lista Referencia al puntero de la lista enlazada.
 */
void addToMemory(std::string nombre, int numero, Contacto*& lista);

/**
 * @brief Muestra toda la información almacenada en la lista enlazada de "Memoria".
 * 
 * @param lista Puntero al primer nodo de la lista enlazada.
 */
void showMemoryList(Contacto* lista);

/**
 * @brief Libera la memoria dinámica asignada para la lista enlazada de "Memoria".
 * 
 * @param lista Referencia al puntero de la lista a liberar.
 */
void freeMemoryData(Contacto*& lista);

/**
 * @brief Elimina un contacto específico de la lista enlazada en "Memoria".
 * 
 * @param nombre Nombre del contacto a eliminar.
 * @param lista Referencia al puntero de la lista enlazada.
 */
void deleteFromMemory(std::string nombre, Contacto*& lista);

#endif // LINKEDLISTFUNCS_HPP
