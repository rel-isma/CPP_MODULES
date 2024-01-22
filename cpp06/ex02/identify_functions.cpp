/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_functions.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:28:24 by rel-isma          #+#    #+#             */
/*   Updated: 2024/01/14 18:46:07 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify_functions.hpp"
#include "derived_classes.hpp"

Base *generate()
{
    srand(static_cast<unsigned int>(time(NULL)));
    int choice = rand() % 3;
    switch (choice)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    default:
        return NULL;
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(p))
    {
        std::cout << "C" << std::endl;
    }
    else
    {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base &p)
{
    try
    {
        A& aRef = dynamic_cast<A &>(p);
        (void)aRef;
        std::cout << "A" << std::endl;

    }
    catch (const std::bad_cast &e)
    {
         try
        {
            B& bRef = dynamic_cast<B &>(p);
            (void)bRef;
            std::cout << "B" << std::endl;
        }
        catch (const std::bad_cast &e)
        {
             try
            {
                C& cRef = dynamic_cast<C &>(p);
                (void)cRef;
                std::cout << "C" << std::endl;
            }
            catch (const std::bad_cast &e)
            {
            }
        }
    }
    
}
