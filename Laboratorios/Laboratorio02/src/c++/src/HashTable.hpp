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

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include "Nodo.hpp" ///< Para usar la estructura Contacto

#define MAX_ELEMENTS 10 ///< Cantidad máxima de buckets en la tabla hash

/**
 * @class Hashtable
 * @brief Clase que implementa una estructura de datos tipo tabla hash.
 * 
 * Esta clase permite almacenar objetos de tipo Contacto utilizando una clave 
 * tipo string. Internamente, utiliza un arreglo de listas enlazadas para manejar
 * colisiones mediante encadenamiento.
 */
class Hashtable {
private:
    /**
     * @brief Arreglo de punteros a nodos que representan los buckets de la tabla hash.
     * 
     * Cada bucket es una lista enlazada de nodos que manejan colisiones.
     */
    Nodo* tablaHash[MAX_ELEMENTS];

public:
    /**
     * @brief Constructor de la clase Hashtable.
     */
    Hashtable();

    /**
     * @brief Inserta un nuevo elemento en la tabla hash.
     * 
     * @param key Clave string usada para calcular el índice.
     * @param value Puntero al contacto que se desea insertar.
     */
    void insertItem(std::string key, Contacto* value);

    /**
     * @brief Elimina un elemento de la tabla hash y devuelve su valor.
     * 
     * @param key Clave del contacto a eliminar.
     * @return Puntero al contacto eliminado o nullptr si no se encontró.
     */
    Contacto* deleteItem(std::string key);

    /**
     * @brief Muestra por consola el contenido de la tabla hash.
     */
    void displayHash();

    /**
     * @brief Calcula el índice en el arreglo a partir de una clave string.
     * 
     * @param key Clave string sobre la cual se aplica la función hash.
     * @return Índice correspondiente al bucket.
     */
    int hashFunction(std::string key);

    /**
     * @brief Libera la memoria utilizada por la tabla hash.
     */
    void freeHashTable();
};

#endif // HASHTABLE_HPP