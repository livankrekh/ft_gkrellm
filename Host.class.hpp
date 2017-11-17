// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Host.class.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/11 20:10:22 by oposhiva          #+#    #+#             //
//   Updated: 2017/11/11 20:10:23 by oposhiva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HOST_CLASS_HPP
# define HOST_CLASS_HPP

#include <string>
#include <iostream>
#include "IMonitorModule.class.hpp"

class	Host : public IMonitorModule {

public:
	Host();
	Host( Host const & rhs );

	~Host();
	std::string	getInfo() const;
	void		print();


	Host &	operator=( Host const & rhs );
};

#endif