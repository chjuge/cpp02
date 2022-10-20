/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:30:22 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/20 13:11:11 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int value;
	static int const ft_bits = 8;

public:
	Fixed();
	Fixed(int const par_int);
	Fixed(float const par_float);
	Fixed(Fixed const &other);
	~Fixed();

	Fixed &	operator =(Fixed const &other);

	Fixed	operator +(Fixed const &other);
	Fixed	operator -(Fixed const &other);
	Fixed	operator *(Fixed const &other);
	Fixed	operator /(Fixed const &other);
	
	Fixed	operator +(Fixed const &other) const;
	Fixed	operator -(Fixed const &other) const;
	Fixed	operator *(Fixed const &other) const;
	Fixed	operator /(Fixed const &other) const;

	Fixed & operator ++();
	Fixed & operator --();
	Fixed operator ++(int par);
	Fixed operator --(int par);

	bool	operator <(Fixed const & src);
	bool	operator >(Fixed const & src);
	bool	operator >=(Fixed const & src);
	bool	operator <=(Fixed const & src);
	bool	operator ==(Fixed const & src);
	bool	operator !=(Fixed const & src);

	bool	operator >(Fixed const & src) const;
	bool	operator <(Fixed const & src) const;
	bool	operator >=(Fixed const & src) const;
	bool	operator <=(Fixed const & src) const;
	bool	operator ==(Fixed const & src) const;
	bool	operator !=(Fixed const & src) const;

	int getRawBits(void) const;
	void setRawBits(int const raw);
	
	float toFloat(void) const;
	int toInt(void) const;

	static Fixed & min (Fixed & p1, Fixed & p2);
	static Fixed & max (Fixed & p1, Fixed & p2);
	static Fixed const & max (Fixed const & p1, Fixed const & p2);
	static Fixed const & min (Fixed const & p1, Fixed const & p2);
};

std::ostream & operator<<(std::ostream &stream, Fixed const &src);


#endif