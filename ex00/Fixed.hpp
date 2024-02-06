/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:28:22 by adhaka            #+#    #+#             */
/*   Updated: 2024/01/28 05:05:12 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int fpValue;
		static const int fractionalBits;

	public:
		Fixed();
		~Fixed();

		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);


		int  getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
