// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Date.class.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/11 22:13:45 by oposhiva          #+#    #+#             //
//   Updated: 2017/11/11 22:13:46 by oposhiva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DATE_CLASS_HPP
# define DATE_CLASS_HPP

#include <string>
#include <iostream>
#include "IMonitorModule.class.hpp"

class	Date : public IMonitorModule {

public:
	Date();
	Date( Date const & rhs );

	~Date();
	std::string	getInfo() const;
	void		print();


	Date &	operator=( Date const & rhs );
};

#endif