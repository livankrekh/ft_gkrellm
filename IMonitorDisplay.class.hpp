// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorDisplay.class.hpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/12 13:04:57 by oposhiva          #+#    #+#             //
//   Updated: 2017/11/12 13:04:57 by oposhiva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMONITORDISPLAY_CLASS_HPP
# define IMONITORDISPLAY_CLASS_HPP

# include "Host.class.hpp"
# include "Date.class.hpp"
# include "System.class.hpp"
# include "RAM.hpp"
# include "Network.class.hpp"
# include "CPU.hpp"
# include "Host.class.hpp"

class	IMonitorDisplay {
private:
private:
	Host	_h;
	Date	_d;
	System	_s;
	RAM		_r;
	Network	_n;
	CPU		_c;
public:
	IMonitorDisplay();
	IMonitorDisplay( IMonitorDisplay const & rhs );

	~IMonitorDisplay();

	Host	&get_h();
	Date	&get_d();
	System	&get_s();
	RAM		&get_r();
	Network	&get_n();
	CPU		&get_c();

	IMonitorDisplay &	operator=( IMonitorDisplay const & rhs );
};

#endif