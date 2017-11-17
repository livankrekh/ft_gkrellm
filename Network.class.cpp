// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Network.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/12 15:14:00 by oposhiva          #+#    #+#             //
//   Updated: 2017/11/12 15:14:00 by oposhiva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Network.class.hpp"
#include <ncurses.h>
#include <sstream>

Network::Network() {
	this->set_x( 0 );
	this->set_y( 29 );
	this->set_width( 54 );
	this->set_height( 6 );
	this->set_name( "       Network throughput module" );
}

Network::Network( Network const &rhs ) {
	*this = rhs;
}

Network &	Network::operator=( Network const &rhs ) {
	this->set_x(rhs.get_x());
	this->set_y(rhs.get_y());
	this->set_width(rhs.get_width());
	this->set_height(rhs.get_height());
	return ( *this );
}

std::string	Network::getInfo() const {
	std::string					ret;
	std::stringstream			stream;
	FILE 						*filename;
	char						buff[1024];

	if(not (filename = popen("/usr/bin/top | /usr/bin/head -n9 | /usr/bin/grep 'Network'", "r")))
		return ( "Error!" );
	while(fgets(buff, sizeof(buff), filename))
		stream << buff;
	pclose( filename );
	ret = " " + stream.str();
	ret.insert(36, 1, '\n');
	ret.insert(37, 2, '\t');
	return ( ret );


}

void Network::print() {
	move(get_y() + 1, get_x() + 1);
	attron(COLOR_PAIR(2));
	printw("%s", (this->get_name()).c_str());
	attroff(COLOR_PAIR(2));
	move(get_y() + 3, get_x() + 1);
	printw("%s", (getInfo()).c_str());
	this->bord();
}

Network::~Network() {}
