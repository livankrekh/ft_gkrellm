/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:26:54 by liabanzh          #+#    #+#             */
/*   Updated: 2017/11/11 15:26:55 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAM_HPP
# define RAM_HPP
# include <string>
# include <iostream>
# include <sys/types.h>
# include <sys/sysctl.h>
# include <mach/vm_statistics.h>
# include <mach/mach_types.h>
# include <mach/mach_init.h>
# include <mach/mach_host.h>
# include <stdexcept>

# include "IMonitorModule.class.hpp"

class 	RAM : public IMonitorModule
{
public:
	RAM(void);
	RAM(RAM const & cp);
	~RAM(void);

	RAM & operator=(RAM const & cp);

	size_t	getAllRAM(void);
	size_t	getUsedRAM(void);
	size_t	getFreeRAM(void);
	size_t	getInactiveRAM(void);
	size_t	getActiveRAM(void);
	size_t	getWire(void);
	size_t	getCount(void);
	size_t	getPageSize(void);
	void	setRAM(void);
	void	setAllRAM(void);
	void 	print(void);

	class 	KERN_EXCEPT : std::exception
	{
	public:
		virtual const char * what(void) const throw();
	};

protected:
	size_t	_allRAM;
	size_t	_usedRAM;
	size_t	_inactiveRAM;
	size_t	_activeRAM;
	size_t	_wire;
	size_t	_lolCount;
	size_t	_pageSize;
	size_t	_freeRAM;
};

std::ostream &	operator<<(std::ostream & out, RAM & cp);

#endif
