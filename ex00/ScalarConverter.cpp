/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:22:22 by marvin            #+#    #+#             */
/*   Updated: 2025/05/05 11:22:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>

bool	isAllDigital(const std::string &input) 
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == '-' || input[i] == '-')
			i++;
		if (!std::isdigit(input[i]))
			return false;
	}
	return true;
}

//idendifier type
ScalarType	detectType(const std::string &input)
{
	if(input == "-inff" || input == "+inff" || input == "nanf")
		return TYPE_SPECIALFLOAT;
	else if (input == "-inf" || input == "+inf" || input == "nan")
		return TYPE_SPECIALDOUBLE;
	else if (input.length() == 1 && !std::isdigit(input[0]))
		return TYPE_CHAR;
	else if (isAllDigital(input))
	{
		return TYPE_INT;
	}
	else if (input.find('.') != std::string::npos && input[input.length() - 1] == 'f')
		return TYPE_FLOAT;
	else if (input.find('.') != std::string::npos && input[input.length() - 1] != 'f')
		return TYPE_DOUBLE;
	return TYPE_INVALID;
}

// | `static_cast`      | 一般的类型转换（如 int 转 float、子类转父类）| `int i = static_cast<int>(3.14);`            |

//input => char
void	convertChar(const std::string &input)
{
	char c = input[0];
	std::cout << "Char: '" << c << "'" << std::endl;
	std::cout << "Int: " << static_cast<int>(c) << std::endl;
	std::cout << "Float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "Double: " << static_cast<double>(c) << ".0" << std::endl;
}

//input => INT 
void	convertInt(const std::string &input)
{
	int value = std::atoi(input.c_str());
	if (value < 32 || value > 126)
		std::cout << "Char: '" << "Non displayable" << "'" << std::endl;
	else
		std::cout << "Char: '*'" << std::endl;
	std::cout << "Int: " << value << std::endl;
	std::cout << "Float: " << value << ".0f" << std::endl;
	std::cout << "Double: " << value << ".0" << std::endl;
}

//input => FLOAT
void	convertFloat(const std::string &input)
{
	float value = std::atof(input.c_str());
	if (value < 32 || value > 126)
		std::cout << "Char: '" << "Non displayable" << "'" << std::endl;
	else
		std::cout << "Char: '*'" << std::endl;
	std::cout << "Int: " << static_cast<int>(value) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Float: " << value << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(value) << std::endl;
}

void	convertDouble(const std::string &input)
{
	double value = std::atof(input.c_str());
	if (value < 32 || value > 126)
		std::cout << "Char: '" << "Non displayable" << "'" << std::endl;
	else
		std::cout << "Char: '*'" << std::endl;
	std::cout << "Int: " << static_cast<int>(value) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "Double: " << value << std::endl;
}

void	convertSpecialFloat(const std::string &input)
{
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: " << input << std::endl;
	std::cout << "Double: " << input.substr(0, input.length() - 1) << std::endl;
}

void	convertSpecialDouble(const std::string &input)
{
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: " << input << "f" << std::endl;
	std::cout << "Double: " << input << std::endl;
}

//output
void	ScalarConverter::convert(const std::string &input)
{
	ScalarType resultType = detectType(input);
	switch (resultType)
	{
	case TYPE_CHAR:
		convertChar(input);
		break;
	case TYPE_INT:
		convertInt(input);
		break;
	case TYPE_FLOAT:
		convertFloat(input);
		break;
	case TYPE_DOUBLE:
		convertDouble(input);
		break;
	case TYPE_SPECIALFLOAT:
		convertSpecialFloat(input);
		break;
	case TYPE_SPECIALDOUBLE:
		convertSpecialDouble(input);
		break;
	
	default:
		break;
	}
}