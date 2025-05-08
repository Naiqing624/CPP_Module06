/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:22:39 by marvin            #+#    #+#             */
/*   Updated: 2025/05/05 11:22:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

enum ScalarType {
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_SPECIALFLOAT,
	TYPE_SPECIALDOUBLE,
	TYPE_INVALID
};

class ScalarConverter
{
	private:
		ScalarConverter();

	public:
		static void convert(const std::string &input);

		
};



#endif