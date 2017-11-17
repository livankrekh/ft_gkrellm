// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/11 20:10:51 by oposhiva          #+#    #+#             //
//   Updated: 2017/11/11 20:10:51 by oposhiva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <ncurses.h>
#include "IMonitorNcurses.class.hpp"

void	color_init() {
	start_color();
	init_color(COLOR_WHITE, 999, 999, 999);
	init_color(COLOR_MAGENTA, 400, 400, 400);
	init_color(COLOR_YELLOW, 999, 500, 0);
	init_color(COLOR_BLUE, 0, 400, 999);
	init_color(COLOR_GREEN, 0, 500, 0);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(8, COLOR_MAGENTA, COLOR_BLACK);
}


void	start_graph() {
	initscr();
	raw();
	color_init();
	curs_set(0);
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	nonl();
	keypad(stdscr, TRUE);
	scrollok(stdscr, TRUE);
}

int main( int argc, char *argv[] ) {
	std::string n = "-n";
	std::string g = "-g";
	if (argc != 2) {
		std::cout << "usage: ./ft_gkrellm [-n | -g ]" << std::endl;
		std::cout << "      ,        ,--,\n"
				"       \\ _ ___/ /\\|\n"
				"        ( )__, )\n"
				"        l/_  '--,\n"
				"         \\ `  / '" << std::endl;
		return ( 0 );
	}
	if (!n.compare(argv[1])) {
		IMonitorNcurses	n;

		start_graph();
		while (true)
		{
			n.display();
			refresh();
			if (getch() == 27)
				break ;
		}
		endwin();
	}
	else if (!g.compare(argv[1])) {

	}
	else
		std::cout << "Invalid flag!" << std::endl;
	return 0;
}
