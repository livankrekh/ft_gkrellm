/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:27:05 by liabanzh          #+#    #+#             */
/*   Updated: 2017/11/11 15:27:06 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RAM.hpp"

RAM::RAM(void)
{
	this->set_x( 0 );
	this->set_y( 21 );
	this->set_width( 54 );
	this->set_height( 8 );
	this->set_name( "       RAM module" );
	this->setAllRAM();
	this->setRAM();
}

RAM::RAM(RAM const & cp)
{
	*this = cp;
}

RAM::~RAM(void)
{
	return ;
}

RAM	& 	RAM::operator=(RAM const & cp)
{
	this->_allRAM = cp._allRAM;
	this->_usedRAM = cp._usedRAM;
	this->_freeRAM = cp._freeRAM;
	return (*this);
}

void	RAM::setAllRAM(void)
{
	size_t	result;
	size_t 	len;

	len = sizeof(result);
	sysctlbyname("hw.memsize", &result, &len, NULL, 0);
	this->_allRAM = result;
}

void	RAM::setRAM(void)
{
	vm_size_t				page_size;
	mach_port_t				mach_port;
	mach_msg_type_number_t	count;
	vm_statistics64_data_t	vm_stats;

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);
	if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
		KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
										(host_info64_t)&vm_stats, &count))
	{
		this->_pageSize = (size_t)page_size;
		this->_freeRAM = (size_t)vm_stats.free_count * (size_t)page_size;
		this->_inactiveRAM = (size_t)vm_stats.inactive_count * (size_t)page_size;
		this->_activeRAM = (size_t)vm_stats.active_count * (size_t)page_size;
		this->_wire = (size_t)vm_stats.wire_count * (size_t)page_size;
		this->_lolCount = (size_t)vm_stats.compressor_page_count * (size_t)page_size;
		this->_usedRAM =	((size_t)vm_stats.active_count +
							(size_t)vm_stats.inactive_count +
							(size_t)vm_stats.wire_count) * (size_t)page_size;
	}
	else
	{
		this->_lolCount = 0;
		this->_pageSize = 0;
		this->_usedRAM = 0;
		this->_freeRAM = 0;
		this->_inactiveRAM = 0;
		this->_activeRAM = 0;
		this->_wire = 0;
		throw KERN_EXCEPT ();
	}
}

size_t 	RAM::getAllRAM(void)
{
	return (this->_allRAM);
}

size_t 	RAM::getUsedRAM(void)
{
	return (this->getAllRAM() - this->getFreeRAM());
}

size_t 	RAM::getFreeRAM(void)
{
	return (this->_freeRAM);
}

size_t 	RAM::getInactiveRAM(void)
{
	return (this->_inactiveRAM);
}

size_t 	RAM::getActiveRAM(void)
{
	return (this->_activeRAM);
}

size_t 	RAM::getWire(void)
{
	return (this->_wire);
}

size_t 	RAM::getCount(void)
{
	return (this->_lolCount);
}

size_t 	RAM::getPageSize(void)
{
	return (this->_pageSize);
}

const char *	RAM::KERN_EXCEPT::what(void) const throw()
{
	return ("ERROR! KERN_SUCCESS! This mean error exist in RAM::getRAM");
}

std::ostream &	operator<<(std::ostream & out, RAM & cp)
{
	try
	{
		cp.setRAM();
	}
	catch (RAM::KERN_EXCEPT & e)
	{
		out << e.what() << std::endl;
		return (out);
	}
	out << "All RAM size: " << cp.getAllRAM() / (1024 * 1024) << " MB" << std::endl;
	out << "RAM in using: " << (cp.getAllRAM() - cp.getFreeRAM()) / (1024 * 1024) << " MB" << std::endl;
	out << "Free RAM size: " << cp.getFreeRAM() / (1024 * 1024) << " MB" << std::endl;
	out << std::endl;
	out << "DETAILS" << std::endl;
	out << "Active RAM: " << cp.getActiveRAM() / (1024 * 1024) << " MB" << std::endl;
	out << "Inactive RAM: " << cp.getInactiveRAM() / (1024 * 1024) << " MB" << std::endl;
	out << "Wire size: " << cp.getWire() / (1024 * 1024) << " MB" << std::endl;
	out << "Page size: " << cp.getPageSize() / 1024 << " KB" << std::endl;
	return (out);
}

void	RAM::print() {
	move(get_y() + 1, get_x() + 1);
	attron(COLOR_PAIR(2));
	printw("%s", (this->get_name()).c_str());
	attroff(COLOR_PAIR(2));
	move(get_y() + 3, get_x() + 1);
	this->setRAM();
	printw(" All physical - %llu MB\n  Wired - %llu MB\n  Used - %llu MB\n  Free - %llu MB",
			getAllRAM() / (1024 * 1024), getWire() / (1024 * 1024), getUsedRAM() / (1024 * 1024), getFreeRAM() / (1024 * 1024));
	this->bord();

	refresh();

}
