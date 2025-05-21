/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:57:29 by nacao             #+#    #+#             */
/*   Updated: 2025/05/08 15:32:57 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <time.h>

int main(void)
{
    srand(time(0));
    Base    *base = generate();
    identify(base);

    Base    &base2 = *base;
    identify(&base2);
    
    delete base;
    
    Base    *base1 = generate();
    identify(base1);
    delete base1;
}