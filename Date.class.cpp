// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Date.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/11 22:13:39 by oposhiva          #+#    #+#             //
//   Updated: 2017/11/11 22:13:40 by oposhiva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Date.class.hpp"
#include <ncurses.h>

Date::Date() {
	this->set_x( 0 );
	this->set_y( 6 );
	this->set_width( 54 );
	this->set_height( 5 );
	this->set_name( "       Date/time module  " );
}

Date::Date( Date const &rhs ) {
	*this = rhs;
}

Date &	Date::operator=( Date const &rhs ) {
	this->set_x(rhs.get_x());
	this->set_y(rhs.get_y());
	this->set_width(rhs.get_width());
	this->set_height(rhs.get_height());
	return ( *this );
}

std::string	Date::getInfo() const {
	time_t              tm;
	std::string         ret;
	struct tm			*s_tm;
	char                buff[80];

	time(&tm);
	s_tm = localtime(&tm);
	strftime(buff, 80, " Date & time > %e/%m/%Y %I:%M:%S%p.", s_tm);

	ret = std::string(buff);
	return ( ret );
}

void	Date::print() {
	move(get_y() + 1, get_x() + 1);
	attron(COLOR_PAIR(2));
	printw("%s", (this->get_name()).c_str());
	attroff(COLOR_PAIR(2));
	move(get_y() + 3, get_x() + 1);
	printw("%s", (getInfo()).c_str());
	this->bord();
	refresh();
}

Date::~Date() {}