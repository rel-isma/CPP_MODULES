/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:53:00 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/22 14:33:07 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(NULL), length(0) {}

template <typename T>
Array<T>::Array(unsigned int size) : elements(NULL), length(0)
{
    allocateMemory(size);
}

template <typename T>
Array<T>::Array(const Array &other) : elements(NULL), length(0)
{
    *this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        unsigned int newSize = other.size();
        allocateMemory(newSize);
        for (unsigned int i = 0; i < newSize; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] elements;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= length)
    {
        throw std::out_of_range("Index is out of bounds");
    }
    return elements[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return length;
}

template <typename T>
void Array<T>::allocateMemory(unsigned int size)
{
    delete[] elements;

    elements = new T[size];
    length = size;
}

