/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:50:40 by marvin            #+#    #+#             */
/*   Updated: 2025/05/08 15:49:12 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>
#include <cstdlib>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>


Base::~Base()
{
}

Base	*generate(void)
{

    int r = rand() % 3;
    if (r == 1)
        return new A();
    else if (r == 2)
        return new B();
    else
        return new C();
}

void	identify(Base *p)
{
    if (dynamic_cast<A *>(p))
    {
        std::cout << "The actual type of the object pointed to by p: A" << std::endl;
        return ;
    }
    else if (dynamic_cast<B *>(p))
    {
        std::cout << "The actual type of the object pointed to by p: B" << std::endl;
        return ;
    }
    else if (dynamic_cast<C *>(p))
    {
        std::cout << "The actual type of the object pointed to by p: C" << std::endl;
        return ;
    }
}

void	identify(Base &p)
{
    try
    {
        if (dynamic_cast<A *>(&p))
            std::cout << "The actual type of the object pointed to by p: A" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        if (dynamic_cast<B *>(&p))
            std::cout << "The actual type of the object pointed to by p: B" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        if (dynamic_cast<C *>(&p))
            std::cout << "The actual type of the object pointed to by p: C" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
}
