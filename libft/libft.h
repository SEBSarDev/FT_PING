/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:56:04 by ssar              #+#    #+#             */
/*   Updated: 2024/05/21 15:58:16 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t n);
char			*ft_strnstr(const char *str, const char *to_find, size_t n);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t nbr, size_t size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_itoa_base(long long n, char *base_to, int excep);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *n);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *n);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *));
int	ft_strcmp(const char *s1, const char *s2);
/* PRINTF */
typedef struct s_flag
{
	int	pad_zero;
	int	to_left;
	int	larg_min;
	int	precision;
	int	isprecision;
	int	c_is_zero;
}				t_flag;
int				ft_is_in(char *base, char c);
int				ft_printf(const char *str, ...);
void			ft_put_percent(const char *str, size_t *i, size_t *l);
void			ft_def_conv(const char *str, size_t *i, va_list ap, size_t *l);
char			*ft_itoa_base(long long n, char *base_to, int excep);
void			ft_init_exception(int excep, char *tab, int *len);
int				ft_size_of_conv(long long n, char *base_to);
int				ft_show(char *str, t_flag *stock);
int				ft_len(char *str);
void			ft_char_to_str(unsigned char c, char **p, t_flag *stock);
void			ft_conv_nbr(va_list cpy, const char *str, char **p, int i);
t_flag			ft_init_flag(const char *str, va_list cpy, t_flag stock);
int				ft_next(const char *str);
char			*ft_treat_flag(char *p, t_flag flag, char c);
void			ft_treat_pad_zero(char **tab);
void			ft_treat_to_left(char **tab);
char			*ft_treat_larg_min(char *tab, int larg_min);
char			*ft_treat_prec_nb(char *tab, int precision, int j);
char			*ft_treat_prec_s(char *tab, int precision);
int				ft_cmp(char *s1, char *s2);
t_flag			ft_default_flag(void);
char			*ft_free_tab(char *tab);
int				ft_len_nb(char *tab);
char			*ft_dup2(char *s);

#endif
