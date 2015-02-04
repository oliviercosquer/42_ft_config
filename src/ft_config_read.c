/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 23:27:12 by olivier           #+#    #+#             */
/*   Updated: 2015/02/03 22:54:05 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_config.h>

static	void	ft_config_read_data(int fd, t_section *list, char **line)
{
	int		gnl;
	int		is_valid;
	char	*data_name;
	char	*data;

	is_valid = 1;
	ft_strdel(line);
	gnl = get_next_line(fd, line);
	while (is_valid && gnl >= 0)
	{
		if (ft_config_is_data(*line))
		{
			data_name = ft_config_parse_data_name(*line);
			data = ft_config_parse_data_data(*line);
			(void)list;
			ft_config_add_data(list, data_name, data);
			ft_strdel(line);
			gnl = get_next_line(fd, line);
		}
		else
			is_valid = 0;
	}
}

static	void	ft_config_read_section(int fd, t_config *config, char **line)
{
	t_section	*section;

	section = ft_config_add_section(config, ft_config_parse_section_name(*line));
	ft_config_read_data(fd, section, line);
}

t_config		*ft_config_read(char *filename)
{
	int			fd;
	t_config	*config;
	char		*line;
	int			gnl;

	fd = 0;
	config = ft_config_new(filename);
	fd = open(filename, O_RDONLY);
	line = NULL;
	gnl = get_next_line(fd, &line);
	while (gnl)
	{
		if (ft_config_is_valid_line(line))
		{
			if (ft_config_is_section(line))
				ft_config_read_section(fd, config, &line);
			ft_strdel(&line);
			gnl = get_next_line(fd, &line);
		}
		else
		{
			printf("Fichier de config invalide!\n");
			gnl = -1;
			//free les sections et data
		}
	}
	close (fd);
	return (config);
}