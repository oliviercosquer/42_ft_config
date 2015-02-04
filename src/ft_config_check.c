/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 21:37:01 by olivier           #+#    #+#             */
/*   Updated: 2015/02/04 22:46:57 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_config.h>

int				ft_config_is_valid_line(char *str)
{
	if (ft_config_is_comment(str))
		return (1);
	else if (ft_config_is_section(str))
		return (1);
	else if (ft_config_is_data(str) && ft_config_is_data_valid(str))
		return (1);
	else if (ft_strlen(str) == 0)
		return (1);
	return (0);
}

int				ft_config_is_section(char *str)
{
	return (str && *str == FT_CONFIG_SECTION_PREFIX ? 1 : 0);
}

int				ft_config_is_comment(char *str)
{
	return (str && *str == FT_CONFIG_COMMENT_PREFIX ? 1 : 0);
}

int				ft_config_is_data(char *str)
{
	return (str && *str == FT_CONFIG_DATA_PREFIX ? 1 : 0);
}

int				ft_config_is_data_valid(char *str)
{
	char	*tmp;

	if (ft_config_is_data(str))
	{
		tmp = str + 1;
		if ((tmp = ft_strchr(str, FT_CONFIG_DATA_DELIMITER)))
		{
			tmp += 1;
			if (ft_strlen(tmp))
				return (1);
		}
	}
	return (0);
}