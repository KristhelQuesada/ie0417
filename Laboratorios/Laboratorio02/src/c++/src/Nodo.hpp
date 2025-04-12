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

#ifndef NODO_HPP
#define NODO_HPP

#include "Contacto.hpp" ///< Para usar la estructura Contacto

/**
 * @struct Nodo
 * @brief Nodo utilizado para construir listas enlazadas en la tabla hash.
 *
 * Esta estructura permite manejar colisiones en la tabla hash mediante
 * encadenamiento directo (direct chaining). Cada nodo almacena un puntero
 * a un contacto existente (de la lista enlazada del Cloud) y un puntero
 * al siguiente nodo en la lista.
 * 
 * Se evita añadir un nuevo puntero de encadenamiento a la estructura `Contacto`,
 * reutilizando esta estructura auxiliar para recorrer elementos que comparten
 * el mismo índice de hash.
 */
struct Nodo {
    /**
     * @brief Puntero al contacto asociado con este nodo.
     * 
     * Se refiere a un contacto ya existente en la lista del Cloud.
     */
    Contacto* ptrContactValue;

    /**
     * @brief Puntero al siguiente nodo en la lista de colisiones del mismo bucket.
     */
    Nodo* siguiente;
};

#endif // NODO_HPP
