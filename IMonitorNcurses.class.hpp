// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorNcurses.class.hpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/12 18:55:21 by oposhiva          #+#    #+#             //
//   Updated: 2017/11/12 18:55:22 by oposhiva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMONITORNCURSES_CLASS_HPP
# define IMONITORNCURSES_CLASS_HPP

# include "IMonitorDisplay.class.hpp"
# include "IMonitorModule.class.hpp"
# include "Host.class.hpp"
# include "Date.class.hpp"
# include "System.class.hpp"
# include "RAM.hpp"
# include "Network.class.hpp"
# include "CPU.hpp"
# include <list>
# include <iostream>

class	IMonitorNcurses : public IMonitorDisplay {
public:
	IMonitorNcurses();
	IMonitorNcurses( IMonitorNcurses const & rhs );

	~IMonitorNcurses();

	void	display();

	IMonitorNcurses &	operator=( IMonitorNcurses const & rhs );
};

#endif


