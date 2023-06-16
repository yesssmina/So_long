/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:01:40 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/16 21:32:41 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(int argc, char	**argv)
{
	
	if (argc != 2)
		error_mess("Error\nMets la map choisie en 2e argument! (./map/...)\n");

	check_parsing_final(argv[1]);
	return (0);
}
