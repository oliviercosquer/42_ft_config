/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_parse_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 00:18:30 by olivier           #+#    #+#             */
/*   Updated: 2015/02/04 00:26:19 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_config.h>

t_path			*ft_config_parse_path(char *str)
{
	t_path	*path;
	char	*section_pos;
	char	*data_name_pos;
	char	*data_pos;

	path = (t_path *)malloc(sizeof(t_path));
	if (path)
	{
		section_pos = ft_strchr(str, FT_CONFIG_PATH_DELIMITER);
		path->section ft_strnew(section_pos - str);
		if (path->section)
			ft_strsub(path->section, str, str - section_pos);
		data_name_pos = ft_strchr(section_pos + 1, FT_CONFIG_PATH_DELIMITER);
		path->data_name = ft_strnew(data_name_pos - section_pos);
		if (path->data_name)
			ft_strsub(path->data_name, section_pos + 1,
				data_name_pos - (section_pos + 1))
		path->data;
	}
	return (path);
}
void			*ft_config_del_path(t_path **path);