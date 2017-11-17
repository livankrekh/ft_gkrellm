// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorDisplay.class.cpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/12 13:04:51 by oposhiva          #+#    #+#             //
//   Updated: 2017/11/12 13:04:52 by oposhiva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "IMonitorDisplay.class.hpp"
#include <ncurses.h>

IMonitorDisplay::IMonitorDisplay() {}

IMonitorDisplay::IMonitorDisplay( IMonitorDisplay const &rhs ) {
	*this = rhs;
}

IMonitorDisplay &	IMonitorDisplay::operator=( IMonitorDisplay const &rhs ) {
	( void )rhs;
	return ( *this );
}

IMonitorDisplay::~IMonitorDisplay() {}

Host &		IMonitorDisplay::get_h() {
	return _h;
}

Date &		IMonitorDisplay::get_d() {
	return _d;
}

System &	IMonitorDisplay::get_s() {
	return _s;
}

RAM &		IMonitorDisplay::get_r() {
	return _r;
}

Network &	IMonitorDisplay::get_n() {
	return _n;
}

CPU &		IMonitorDisplay::get_c() {
	return _c;
}
