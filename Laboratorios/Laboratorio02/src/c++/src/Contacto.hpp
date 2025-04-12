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

#ifndef CONTACTO_HPP
#define CONTACTO_HPP

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Estructura que representa un contacto en una lista enlazada.
 * 
 * Esta estructura puede utilizarse tanto para representar un único contacto
 * como para formar parte de una lista enlazada de contactos. Si se usa como
 * contacto individual, el miembro `siguiente` debe inicializarse como `nullptr`.
 */
struct Contacto {
    /**
     * @brief Nombre del contacto.
     */
    string name;

    /**
     * @brief Número de teléfono del contacto.
     */
    unsigned int phone;

    /**
     * @brief Puntero al siguiente contacto en la lista.
     * 
     * Si no se usa una lista enlazada, este valor debe ser `nullptr`.
     */
    Contacto* siguiente;
};

#endif // CONTACTO_HPP