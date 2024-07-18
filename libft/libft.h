/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:28:50 by qhauuy            #+#    #+#             */
/*   Updated: 2024/04/26 22:54:49 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

/* char */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/* string */
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *s, const char *delimiter);
char	**ft_split_quote(const char *s, char c);
int		ft_size_inside_quotes(const char *s);
size_t	get_length(char **s);

/* list */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list	*list_new(void *content);
int		list_size(t_list *list);
t_list	*list_last(t_list *list);
void	list_print(t_list *list, void (*ft_print)(void *content));
void	list_clear(t_list **list, void (*ft_free)(void *content));
void	list_add_front(t_list **list, t_list *node);
void	list_add_back(t_list **list, t_list	*node);

/* memory */
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		save_malloc(void *p, t_list **l, void (*ft_free)(void *content));
void	*ft_calloc_list(\
	size_t count, size_t size, t_list **l, void (*ft_free)(void *content));
char	*ft_strdup_list(\
	const char *s, t_list **l, void (*ft_free)(void *content));
void	ft_free(void *p, t_list **l, void (*ft_free)(void *content));
void	deep_free(char **a, size_t i);
void	deep_free_int(int **a, size_t i);

/* print */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf(const char *s, ...);

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);
int		ft_length_unsigned(unsigned long n);
int		ft_length_unsigned_hex(unsigned long n);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

char	*get_next_line(int fd);

#endif
