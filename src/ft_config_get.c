/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 21:24:23 by olivier           #+#    #+#             */
/*   Updated: 2015/02/03 23:01:41 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_config.h>

int				ft_config_get_int(t_config *config, char *path)
{
	t_data	*data;

	data = ft_config_get(config, path);
	if (data)
	{
		return (ft_atoi(data->data));
	}
	return (0);
}

char			*ft_config_get_string(t_config *config, char *path)
{
	t_data	*data;

	data = ft_config_get(config, path);
	if (data)
	{
		return (ft_strdup(data->data));
	}
	return (NULL);
}

int				ft_config_get_bool(t_config *config, char *path)
{
	return (ft_config_get_int(config, path));
}