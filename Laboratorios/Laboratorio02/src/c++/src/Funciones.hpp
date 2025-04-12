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

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <string>

/**
 * @brief Verifica la validez de la opción ingresada por el usuario en un menú.
 *
 * Esta función analiza una cadena de entrada proporcionada por el usuario
 * y devuelve un valor entero. Si la entrada no es válida, se devuelve un valor
 * entero fuera del rango permitido especificado por el parámetro `out_range`.
 *
 * @param input Cadena ingresada por el usuario.
 * @param out_range Valor entero que representa el límite superior fuera del rango válido.
 * @return int Opción válida como entero o un valor fuera de rango si la entrada no es válida.
 */
int verifyMenuOption(std::string input, int out_range);

#endif // FUNCIONES_HPP