/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:31:26 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/16 21:32:51 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *fichier)
{
	int i;

	i = ft_strlen(fichier) - 1;
	if (fichier[i] == 'r' && fichier[i - 1] == 'e' && fichier[i - 2] == 'b' && 
		fichier[i - 3] == '.' )
			return (1);
	return (0);	
}