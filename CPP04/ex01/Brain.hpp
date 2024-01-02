/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:12:37 by rel-isma          #+#    #+#             */
/*   Updated: 2023/12/10 15:15:27 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
public:
    Brain();
    ~Brain();
    Brain(const std::string& type);
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    void printIdeas() const;

private:
    std::string ideas[100];
};

#endif


