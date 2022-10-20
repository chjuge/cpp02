/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:31:30 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/20 13:17:50 by mproveme         ###   ########.fr       */
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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}
void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
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





Fixed	Fixed::operator +(Fixed const &other)
{
	Fixed temp = *this;

	temp.value = this->value + other.value;
	return (temp);
}
Fixed	Fixed::operator -(Fixed const &other)
{
	Fixed temp = *this;

	temp.value = this->value - other.value;
	return (temp);
}
Fixed	Fixed::operator *(Fixed const &other)
{
	Fixed temp = *this;

	temp.value = ((this->value * other.value) >> this->ft_bits);
	return (temp);
}
Fixed	Fixed::operator /(Fixed const &other)
{
	Fixed temp = *this;

	temp.value = (this->value << this->ft_bits) / other.value;
	return (temp);
}






Fixed	Fixed::operator +(Fixed const &other) const
{
	Fixed temp = *this;

	temp.value = this->value + other.value;
	return (temp);
}
Fixed	Fixed::operator -(Fixed const &other) const
{
	Fixed temp = *this;

	temp.value = this->value - other.value;
	return (temp);
}
Fixed	Fixed::operator *(Fixed const &other) const
{
	Fixed temp = *this;

	temp.value = ((this->value * other.value) >> this->ft_bits);
	return (temp);
}
Fixed	Fixed::operator /(Fixed const &other) const
{
	Fixed temp = *this;

	temp.value = (this->value << this->ft_bits) / other.value;
	return (temp);
}





Fixed & Fixed::operator ++()
{
	this->value++;
	return (*this);
}
Fixed & Fixed::operator --()
{
	this->value--;
	return(*this);
}
Fixed Fixed::operator ++(int par)
{
	Fixed temp(*this);

	this->value++;
	return(temp);
}
Fixed Fixed::operator --(int par)
{
	Fixed temp(*this);

	this->value--;
	return(temp);
}



bool	Fixed::operator <(Fixed const & src)
{
	return (this->value < src.value);
}
bool	Fixed::operator >(Fixed const & src)
{
	return (this->value > src.value);
}
bool	Fixed::operator >=(Fixed const & src)
{
	return (this->value <= src.value);
}
bool	Fixed::operator <=(Fixed const & src)
{
	return (this->value <= src.value);
}
bool	Fixed::operator ==(Fixed const & src)
{
	return (this->value == src.value);
}
bool	Fixed::operator !=(Fixed const & src)
{
	return (this->value != src.value);
}




bool	Fixed::operator <(Fixed const & src) const
{
	return (this->value < src.value);
}
bool	Fixed::operator >(Fixed const & src) const
{
	return (this->value > src.value);
}
bool	Fixed::operator >=(Fixed const & src) const
{
	return (this->value <= src.value);
}
bool	Fixed::operator <=(Fixed const & src) const
{
	return (this->value <= src.value);
}
bool	Fixed::operator ==(Fixed const & src) const
{
	return (this->value == src.value);
}
bool	Fixed::operator !=(Fixed const & src) const
{
	return (this->value != src.value);
}


Fixed & Fixed::min (Fixed & p1, Fixed & p2)
{
	return (p1 < p2? p1 : p2);
}
Fixed & Fixed::max (Fixed & p1, Fixed & p2)
{
	return (p1 > p2? p1 : p2);
}
Fixed const & Fixed::max (Fixed const & p1, Fixed const & p2)
{
	return (p1 > p2? p1 : p2);
}
Fixed const & Fixed::min (Fixed const & p1, Fixed const & p2)
{
	return (p1 < p2? p1 : p2);
}