/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:45:22 by liabanzh          #+#    #+#             */
/*   Updated: 2017/11/12 13:45:24 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "CPU.hpp"

static unsigned long long _previousTotalTicks = 0;
static unsigned long long _previousIdleTicks = 0;

CPU::CPU(void)
{
	this->set_x( 0 );
	this->set_y( 35 );
	this->set_width( 54 );
	this->set_height( 7 );
	this->set_name( "       CPU module" );
	this->setCPUName();
	this->setCPU();
}

CPU::CPU(CPU const & cp)
{
	*this = cp;
}

CPU::~CPU(void)
{
	return ;
}

CPU & CPU::operator=(CPU const & cp)
{
	this->_name = cp._name;
	this->_percent = cp._percent;
	return (*this);
}

void	CPU::setCPUName(void)
{
	char	*CPUname[5000];
	size_t	len = sizeof(char) * 5000;

	sysctlbyname("machdep.cpu.brand_string", &CPUname, &len, NULL, 0);
	this->_model.append((char*)CPUname);
}

float	CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
	unsigned long long	totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
	unsigned long long	idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;
	float 				ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
	_previousTotalTicks = totalTicks;
	_previousIdleTicks  = idleTicks;
	return ret;
}

float	GetCPULoad()
{
	host_cpu_load_info_data_t cpuinfo;
	mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
	{
		unsigned long long totalTicks = 0;
		for (int i = 0; i < CPU_STATE_MAX; i++)
			totalTicks += cpuinfo.cpu_ticks[i];
		return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
	}
	else
		return -1.0f;
}

void	CPU::setCPU(void)
{
	this->_percent = GetCPULoad() * 100.0;
	this->_idl = 100.0 - this->_percent;
	this->_kernel = 0;
	this->_user = 0;
}

float		CPU::getPercentCPU(void)
{
	return (this->_percent);
}

std::string	CPU::getCPUName(void)
{
	return (this->_model);
}

float		CPU::getKernelCPU(void)
{
	return (this->_kernel);
}

float		CPU::getUserCPU(void)
{
	return (this->_user);
}

float		CPU::getIdlCPU(void)
{
	return (this->_idl);
}

const char * CPU::KERN_EXCEPT::what(void) const throw()
{
	return ("ERROR! KERN_EXCEPT in CPU!");
}

std::ostream &	operator<<(std::ostream & out, CPU & cp)
{
	cp.setCPU();
	std::cout.setf(std::ios::fixed);
	std::cout.precision(4);
	out << "CPU Name: " << cp.getCPUName() << std::endl;
	out << "CPU using percent: " << cp.getPercentCPU() << "%" << std::endl;
	out << "Kernel CPU using: " << cp.getKernelCPU() << "%" << std::endl;
	out << "User CPU using: " << cp.getUserCPU() << "%" << std::endl;
	out << "Free CPU: " << cp.getIdlCPU() << "%" << std::endl;
	return (out);
}

void 	CPU::print() {
	move(get_y() + 1, get_x() + 1);
	attron(COLOR_PAIR(2));
	printw("%s", (this->get_name()).c_str());
	attroff(COLOR_PAIR(2));
	move(get_y() + 3, get_x() + 1);
	printw(" CPU model - %s\n", getCPUName().c_str());
	this->setCPU();
	printw("  Load CPU percent - %.2f%%\n", getPercentCPU());
	printw("  Free CPU - %.2f%%\n", getIdlCPU());
	this->bord();

	refresh();

}
