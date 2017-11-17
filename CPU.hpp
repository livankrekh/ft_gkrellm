/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:45:13 by liabanzh          #+#    #+#             */
/*   Updated: 2017/11/12 13:45:16 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_HPP
# define CPU_HPP
# include <string>
# include <iostream>
# include <sys/types.h>
# include <sys/sysctl.h>
# include <unistd.h>
# include <mach/mach_init.h>
# include <mach/mach_error.h>
# include <mach/mach_host.h>
# include <mach/vm_map.h>
# include "IMonitorModule.class.hpp"

class 	CPU  : public IMonitorModule
{
public:
	CPU(void);
	CPU(CPU const & cp);
	~CPU(void);

	CPU & operator=(CPU const & cp);

	// size_t	getAllCPU(void);
	// size_t	getUsedCPU(void);
	// size_t	getFreeCPU(void);
	float		getPercentCPU(void);
	float		getKernelCPU(void);
	float		getUserCPU(void);
	float		getIdlCPU(void);
	std::string getCPUName(void);
	void		setCPUName(void);
	void		setCPU(void);
	void 		print(void);

	class 	KERN_EXCEPT : std::exception
	{
	public:
		virtual const char * what(void) const throw();
	};

protected:
	std::string	_model;
	float		_kernel;
	float		_user;
	float		_idl;
	float		_percent;
};

std::ostream &	operator<<(std::ostream & out, CPU & cp);

#endif
