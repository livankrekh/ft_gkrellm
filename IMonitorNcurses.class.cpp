// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorNcurses.class.cpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/12 18:55:18 by oposhiva          #+#    #+#             //
//   Updated: 2017/11/12 18:55:18 by oposhiva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "IMonitorNcurses.class.hpp"


IMonitorNcurses::IMonitorNcurses() {}


void	IMonitorNcurses::display() {
	get_h().print();
	get_d().print();
	get_s().print();
	get_r().print();
	get_n().print();
	get_c().print();
}

IMonitorNcurses::IMonitorNcurses( IMonitorNcurses const &rhs ) {
	*this = rhs;
}

IMonitorNcurses &	IMonitorNcurses::operator=( IMonitorNcurses const &rhs ) {
	( void )rhs;
	return ( *this );
}

IMonitorNcurses::~IMonitorNcurses() {}