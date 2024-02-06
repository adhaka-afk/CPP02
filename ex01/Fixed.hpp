/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:29:22 by adhaka            #+#    #+#             */
/*   Updated: 2024/01/28 06:05:07 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fpValue;
		static const int fractionalBits;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &src);
		Fixed(const int intValue);
		Fixed(const float floatValue);

		Fixed &operator = (const Fixed &src);

		int   getRawBits(void) const;
		void  setRawBits(int const raw);
		float toFloat(void) const;
		int   toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
