// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   System.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/12 13:43:44 by oposhiva          #+#    #+#             //
//   Updated: 2017/11/12 13:43:45 by oposhiva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "System.class.hpp"
#include <ncurses.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <pwd.h>

System::System() {
	this->set_x( 0 );
	this->set_y( 11 );
	this->set_width( 54 );
	this->set_height( 10 );
	this->set_name( "       OS info module" );
}

System::System( System const &rhs ) {
	*this = rhs;
}

System &	System::operator=( System const &rhs ) {
	this->set_x(rhs.get_x());
	this->set_y(rhs.get_y());
	this->set_width(rhs.get_width());
	this->set_height(rhs.get_height());
	return ( *this );
}

std::string	System::getInfo() const {
	std::string     ret;
	struct utsname	host;

	uname(&host);

	ret = " System name > ";
	ret.append(host.sysname);
	ret += "\n  Release > ";
	ret.append(host.release);
	ret += "\n  Version > ";
	ret.append(host.version);
	ret += "\n  Machine > ";
	ret.append(host.machine);
	ret += "\n";
	ret.insert(82, 1, '\n');
	ret.insert(83, 2, ' ');
	ret.insert(115, 1, '\n');
	ret.insert(116, 2, ' ');
	//ret[80] = '\n';
	//ret[81] = ' ';
	return ( ret );

}

void System::print() {
	move(get_y() + 1, get_x() + 1);
	attron(COLOR_PAIR(2));
	printw("%s", (this->get_name()).c_str());
	attroff(COLOR_PAIR(2));
	move(get_y() + 3, get_x() + 1);
	printw("%s", (getInfo()).c_str());
	this->bord();

	refresh();

}

System::~System() {}