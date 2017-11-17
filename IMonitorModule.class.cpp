// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorModule.class.cpp                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/12 12:56:08 by oposhiva          #+#    #+#             //
//   Updated: 2017/11/12 12:56:09 by oposhiva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "IMonitorModule.class.hpp"
#include <ncurses.h>

IMonitorModule::IMonitorModule() {}

IMonitorModule::IMonitorModule( IMonitorModule const &rhs ) {
	*this = rhs;
}

IMonitorModule& IMonitorModule::operator=( IMonitorModule const &rhs ) {
	this->_x = rhs._x;
	this->_y = rhs._y;
	this->_width = rhs._width;
	this->_height = rhs._height;
	return ( *this );
}

void IMonitorModule::bord() {
	char	c;

	c = ' ';
	move(_y, _x);
	attron(COLOR_PAIR(7));
	hline(c, _width + 1);
	vline(c, _height + 1);
	move(_y + 2, _x + 1);
	attron(COLOR_PAIR(8));
	hline('*', _width);
	attron(COLOR_PAIR(7));
	move(_y + _height, _x);
	hline(c, _width + 1);
	move(_y, _x + _width);
	vline(c, _height + 1);
	attroff(COLOR_PAIR(7));
}

int		IMonitorModule::get_x() const {
	return _x;
}

int		IMonitorModule::get_y() const {
	return _y;
}

int		IMonitorModule::get_width() const {
	return _width;
}

int		IMonitorModule::get_height() const {
	return _height;
}

const	std::string &IMonitorModule::get_name() const {
	return _name;
}

void	IMonitorModule::set_name( const std::string &_name ) {
	this->_name = _name;
}

void IMonitorModule::set_x( int _x ) {
	this->_x = _x;
}

void IMonitorModule::set_y( int _y ) {
	this->_y = _y;
}

void IMonitorModule::set_width( int _width ) {
	this->_width = _width;
}

void IMonitorModule::set_height( int _height ) {
	this->_height = _height;
}

IMonitorModule::~IMonitorModule() {}
