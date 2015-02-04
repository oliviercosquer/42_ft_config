/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 22:04:15 by olivier           #+#    #+#             */
/*   Updated: 2015/02/03 22:48:07 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_config.h>

char			*ft_config_parse_section_name(char *path)
{
	char	*section_name;
	char	*start;

	start = ft_strchr(path, FT_CONFIG_SECTION_PREFIX) + 1;
	section_name = NULL;
	section_name = ft_strdup(start);
	return (section_name);
}

char			*ft_config_parse_data_name(char *path)
{
	int		pos_delimiter;
	char	*data_name;

	pos_delimiter = ft_strchr(path, FT_CONFIG_DATA_DELIMITER) - path + 1;
	data_name = ft_strnew(pos_delimiter);
	ft_strncpy(data_name, path + 1, pos_delimiter - 2);
	return (data_name);
}

char			*ft_config_parse_data_data(char *path)
{
	char	*data;
	char	*start;

	data = NULL;
	start = ft_strchr(path, FT_CONFIG_DATA_DELIMITER) + 1;
	data = ft_strdup(start);
	return (data);
}