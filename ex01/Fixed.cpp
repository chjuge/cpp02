/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:31:30 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/04 12:35:15 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const par_int) 
{
	std::cout << "Int constructor called" << std::endl;
	this->value = par_int << this->ft_bits;
}

Fixed::Fixed(float const par_float)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = (int)(roundf(par_float * (1 << this->ft_bits)));
	
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.getRawBits();
}

Fixed & Fixed::operator=(Fixed const & other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = other.value;
	return (*this);
}


int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}
void Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float(this->value / (float)(1 << this->ft_bits))));
}

int Fixed::toInt(void) const
{
	return ((int)(this->value >> this->ft_bits));
}

std::ostream & operator<<(std::ostream &stream, Fixed const &src)
{
	stream << src.toFloat();
	return (stream);
}
