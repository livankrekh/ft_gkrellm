// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Network.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/12 15:14:03 by oposhiva          #+#    #+#             //
//   Updated: 2017/11/12 15:14:03 by oposhiva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NETWORK_CLASS_HPP
# define NETWORK_CLASS_HPP

#include <string>
#include <iostream>
#include "IMonitorModule.class.hpp"


class	Network : public IMonitorModule {
public:
	Network();
	Network( Network const & rhs );

	~Network();
	std::string	getInfo() const;
	void		print();


	Network &	operator=( Network const & rhs );
};

#endif