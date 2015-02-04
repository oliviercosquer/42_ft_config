/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 20:44:09 by olivier           #+#    #+#             */
/*   Updated: 2015/02/04 00:18:07 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CONFIG_H
# define FT_CONFIG_H
# define FT_CONFIG_SECTION_PREFIX '!'
# define FT_CONFIG_DATA_PREFIX '$'
# define FT_CONFIG_COMMENT_PREFIX '#'
# define FT_CONFIG_DATA_DELIMITER ':'
# define FT_CONFIG_PATH_DELIMITER '.'
# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>
# include <fcntl.h>
//FOR DEBUG PURPOSE, DELETE BEFORE PUSH
#include <string.h>
#include <errno.h>
typedef struct s_data
{
	char			*data_name;
	char			*data;
	struct	s_data	*next;
}				t_data;
typedef struct s_section
{
	char				*section_name;
	t_data				*data;
	struct	s_section	*next;
}				t_section;
typedef struct s_config
{
	t_section	*sections;
	char		*filename;
}				t_config;
typedef	struct s_path
{
	char	*section;
	char	*data_name;
	char	*data;
}				t_path;
/* Fonctions a utiliser:
* ft_read_config()
* ft_config_get_int()
* ft_config_get_string()
* ft_write_config()
* ft_update_config()
*/

//ft_config.c
t_config		*ft_config_new(char *filename);
void			ft_config_write(t_config *config, char *filename);//@TODO
void			ft_config_update(t_config *config, char *data_path, char *data);//@TODO
//ft_config_del.c @CHECK
void			ft_config_del_config(t_config **config);
//ft_config2.c DONE
t_section		*ft_config_add_section(t_config *config, char *section_name);
t_data			*ft_config_add_data(t_section *section, char *data_name, char *data);
//ft_config_read.c DONE
t_config		*ft_config_read(char *filename);
//ft_config_add.c
void			ft_config_add_int(t_config *config, char *path, int nbr);//@TODO
void			ft_config_add_string(t_config *config, char *path, char *str);//@TODO
//ft_config_get.c
int				ft_config_get_int(t_config *config, char *path);
char			*ft_config_get_string(t_config *config, char *path);//@TODO
int				ft_config_get_bool(t_config *config, char *path);//@TODO
//ft_config_get2.c @CHECK
t_data			*ft_config_get(t_config *config, char *path);
//ftconfig_check.c DONE
int				ft_config_is_valid_line(char *str);
int				ft_config_is_section(char *str);
int				ft_config_is_comment(char *str);
int				ft_config_is_data(char *str);
int				ft_config_is_data_valid(char *str);
//ft_config_parse.c DONE
char			*ft_config_parse_section_name(char *path);
char			*ft_config_parse_data_name(char *path);
char			*ft_config_parse_data_data(char *path);
//ft_config_debug.c DONE
void			ft_config_print(t_config *config);
void			ft_config_print_section(t_section *sections);
void			ft_config_print_data(t_data *list);
//ft_config_path.c
t_path			*ft_config_parse_path(char *path);
void			*ft_config_del_path(t_path **path);
#endif