// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Host.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/11 20:10:15 by oposhiva          #+#    #+#             //
//   Updated: 2017/11/11 20:10:16 by oposhiva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Host.class.hpp"
#include <ncurses.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <pwd.h>

Host::Host() {
	this->set_x( 0 );
	this->set_y( 0 );
	this->set_width( 54 );
	this->set_height( 6 );
	this->set_name( "       Hostname/username module" );
}

Host::Host( Host const &rhs ) {
	*this = rhs;
}

Host &	Host::operator=( Host const &rhs ) {
	this->set_x(rhs.get_x());
	this->set_y(rhs.get_y());
	this->set_width(rhs.get_width());
	this->set_height(rhs.get_height());
	return ( *this );
}

std::string	Host::getInfo() const {
	std::string     ret;
	struct utsname	host;
	struct passwd	*user;

	uname(&host);
	ret = " Hostname > ";
	ret.append(host.nodename);
	ret += "\n";
	user = getpwuid(getuid());
	ret += "  Username > ";
	ret.append(user->pw_name);
	ret += "\n";
	return ( ret );
}

void Host::print() {
	move(get_y() + 1, get_x() + 1);
	attron(COLOR_PAIR(2));
	printw("%s", (this->get_name()).c_str());
	attroff(COLOR_PAIR(2));
	move(get_y() + 3, get_x() + 1);
	printw("%s", (getInfo()).c_str());
	this->bord();

	refresh();

}

Host::~Host() {}