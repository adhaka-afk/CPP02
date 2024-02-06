/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:30:07 by adhaka            #+#    #+#             */
/*   Updated: 2024/01/28 05:30:19 by adhaka           ###   ########.fr       */
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

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &b) const
{
	return this->getRawBits() > b.getRawBits();
}

bool Fixed::operator<(const Fixed &b) const
{
	return this->getRawBits() < b.getRawBits();
}

bool Fixed::operator>=(const Fixed &b) const
{
	return this->getRawBits() >= b.getRawBits();
}

bool Fixed::operator<=(const Fixed &b) const
{
	return this->getRawBits() <= b.getRawBits();
}

bool Fixed::operator==(const Fixed &b) const
{
	return this->getRawBits() == b.getRawBits();
}

bool Fixed::operator!=(const Fixed &b) const
{
	return this->getRawBits() != b.getRawBits();
}

Fixed Fixed::operator+(const Fixed &b) const
{
	return Fixed(this->toFloat() + b.toFloat());
}

Fixed Fixed::operator-(const Fixed &b) const
{
	return Fixed(this->toFloat() - b.toFloat());
}

Fixed Fixed::operator*(const Fixed &b) const
{
	return Fixed(this->toFloat() * b.toFloat());
}

Fixed Fixed::operator/(const Fixed &b) const
{
	if (b.toFloat() == 0)
	{
		std::cerr << "Error: Why even try 0/0 ?" <<std::endl;
		return Fixed();
	}
	return Fixed(this->toFloat() / b.toFloat());
}

Fixed &Fixed::operator++(void)
{
	this->fpValue++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed &Fixed::operator--(void)
{
	this->fpValue--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return tmp;
}
