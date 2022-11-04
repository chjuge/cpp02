/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:30:22 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/04 12:24:21 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int value;
	static int const ft_bits = 8;

public:
	Fixed();
	Fixed(Fixed const &other);
	~Fixed();

	Fixed &operator=(Fixed const &other);
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
