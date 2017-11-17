// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   System.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/12 13:43:48 by oposhiva          #+#    #+#             //
//   Updated: 2017/11/12 13:43:48 by oposhiva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SYSTEM_CLASS_HPP
# define SYSTEM_CLASS_HPP

#include <string>
#include <iostream>
#include "IMonitorModule.class.hpp"

class	System : public IMonitorModule {

public:
	System();
	System( System const & rhs );

	~System();
	std::string	getInfo() const;
	void		print();


	System &	operator=( System const & rhs );
};

#endif