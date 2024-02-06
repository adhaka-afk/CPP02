/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:29:19 by adhaka            #+#    #+#             */
/*   Updated: 2024/01/28 05:11:09 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fpValue = 0;
}

Fixed::Fixed(const int intValue) : fpValue(intValue << fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue) : fpValue(static_cast<int>(roundf(floatValue * (1 << fractionalBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &src)
	{
		this->setRawBits(src.getRawBits());
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return this->fpValue;
}

void Fixed::setRawBits(int const raw)
{
	this->fpValue = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->fpValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->fpValue >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
