/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:40:34 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/06 18:18:53 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string	string_to_upper(std::string string);

int		main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++)
		std::cout << ::string_to_upper(argv[i]);
	std::cout << std::endl;
	return 0;
}

std::string	string_to_upper(std::string string)
{
	size_t	len(string.size());

	for (size_t i = 0; i < len; i++)
		string[i] = (char)toupper(string[i]);
	return string;
}
