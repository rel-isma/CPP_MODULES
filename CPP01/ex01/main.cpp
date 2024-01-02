/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:28:05 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/05 15:40:46 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
    std::string name = "MyZombie";

    Zombie* zombieHor = zombieHorde(N, name);
    for (int i = 0; i < N; i++)
    {
        zombieHor[i].announce();
    }
    delete[] zombieHor;
}