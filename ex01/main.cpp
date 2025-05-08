/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:01:17 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 15:01:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"
#include "Data.hpp"
#include <iostream>

int	main(void)
{
	Data	*data = new Data;
	data->name = "Aslan";
	data->num = 42;
	std::cout << "Data value: Name -> " << data->name << "\nData value: Num -> " << data->num << std::endl;
	std::cout << "Data pointer adress -> " << data << std::endl;

	uintptr_t	raw = Serialize::serialize(data);
	std::cout << "Serialize data pointer -> " << raw << std::endl;

	Data	*restored = Serialize::deserialize(raw);
	std::cout << "Deserialize data pointer(Back to the original pointer) -> " << restored << std::endl;
	delete	data;
}