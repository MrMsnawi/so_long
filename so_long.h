/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:22:05 by abmasnao          #+#    #+#             */
/*   Updated: 2025/02/02 15:57:07 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_vars
{
	char	**map;
	void	*mlx;
	void	*window;

	void	*player;
	void	*enemy;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*food;

	int		hight;
	int		width;
	int		moves;

	int		wi;
	int		hi;

	int		m_i;
	int		m_j;
	int		m_x;
	int		m_y;

	int		tic;

	int		col_num;
}				t_vars;

typedef struct s_checker
{
	char	checker;
	int		col_num_full;
	int		col_num_check;
}				t_checker;

int		main(int ac, char **av);
int		check_ber(char *av);
char	*get_map(int fd, char *str, t_vars *vars);
void	parse(t_vars *vars, t_checker *checker, char *str, int fd);
void	check_rectangular(char **map, t_vars *vars);
void	check_border(char **map, t_vars *vars);
void	check_invalid_char(char **map, t_vars *vars);
int		check_chars_num(char **map, int player_c, int exit_c, int col_c);
void	check_chars(char **map, t_vars *vars);
void	render(t_vars *vars);
int		food_sprite(t_vars *vars);
int		key_handling(int key_code, t_vars *vars);
int		a_close(t_vars *vars);
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_right(t_vars *vars);
void	move_left(t_vars *vars);
int		find_px(t_vars *vars);
int		find_py(t_vars *vars);
void	check_up(t_vars *vars, int x, int y);
void	check_down(t_vars *vars, int x, int y);
void	check_right(t_vars *vars, int x, int y);
void	check_left(t_vars *vars, int x, int y);
void	enemy_patrol(t_vars *vars);
int		find_ex(t_vars *vars);
int		find_ey(t_vars *vars);
int		find_player(t_vars *vars);
void	you_lose(t_vars *vars);
int		count_col(t_vars *vars);
void	check_enemy(char **map, t_vars *vars);
void	check_valid_path(t_vars *vars, t_checker *checker, char *str);
void	free_f(t_vars *vars);
void	b_close(t_vars *vars);

int		ft_printf(const char *format, ...);
void	check_specifier(const char **format, int *count, va_list list);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_hex_addr(void *p);
int		ft_putnbr(int n);
int		ft_putun(unsigned int n);
int		ft_low_hex(unsigned int hex);
int		ft_up_hex(unsigned int hex);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **list, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif