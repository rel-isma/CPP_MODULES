/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:03:41 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/26 22:51:01 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>


template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;

        MutantStack();
        MutantStack(const MutantStack<T> &src);
        ~MutantStack();

        MutantStack<T> &operator=(const MutantStack<T> &rhs);

        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"

#endif
