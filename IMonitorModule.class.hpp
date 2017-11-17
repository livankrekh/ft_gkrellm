// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorModule.class.hpp                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/12 12:55:45 by oposhiva          #+#    #+#             //
//   Updated: 2017/11/12 12:55:46 by oposhiva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMONITORMODULE_CLASS_HPP
# define IMONITORMODULE_CLASS_HPP

# include <ncurses.h>
# include  <iostream>

class	IMonitorModule {
protected:
	int 		_x;
	int 		_y;
	int			_width;
	int 		_height;
	std::string	_name;
public:
	IMonitorModule();
	IMonitorModule( IMonitorModule const & rhs );

	~IMonitorModule();

	int		get_x() const;
	int		get_y() const;
	int		get_width() const;
	int		get_height() const;
	const std::string &	get_name() const;
	void	set_x( int _x );
	void	set_y( int _y );
	void	set_width( int _width );
	void	set_height( int _height );
	void	set_name( const std::string &_name );

	void 	bord();

	IMonitorModule &	operator=( IMonitorModule const & rhs );
};

#endif
