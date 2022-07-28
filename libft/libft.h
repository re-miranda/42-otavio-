/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:57:29 by oburato           #+#    #+#             */
/*   Updated: 2022/07/28 04:45:21 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../main.h"
# include <stdlib.h>
# include <unistd.h>

/**
 * @file ft_isdigit.c
 * @author oburato
 * @date 2022/04/10 13:52:20
 * @brief The function returns if the character is a digit
 * @param c representation of a character using the integer type
 * @return If the character is a digit it returns 1, otherwise it returns 0
 */
int		ft_isdigit(int c);

/**
 * @file ft_isalpha.c
 * @author oburato
 * @date 2022/04/10 13:35:06
 * @brief The function returns if the character is a alpha
 * @param c representation of a character using the integer type
 * @return If the character is a alpha it returns 1, otherwise it returns 0
 */
int		ft_isalpha(int c);

/**
 * @file ft_isalnum.c
 * @author oburato
 * @date 2022/04/10 13:55:51
 * @brief The function returns if the character is a number
 * @param c representation of a character using the integer type
 * @return If the character is a number it returns 1, otherwise it returns 0
 */
int		ft_isalnum(int c);

/**
 * @file ft_isascii.c
 * @author oburato
 * @date 2022/04/10 14:37:31
 * @brief The function returns if the character is a valid ascii
 * @param c representation of a character using the integer type
 * @return If the character is between 0 and 127 it returns 1, otherwise it returns 0
 */
int		ft_isascii(int c);

/**
 * @file ft_isprint.c
 * @author oburato
 * @date 2022/04/10 14:50:56
 * @brief The function returns if the character is a printable ascii
 * @param c representation of a character using the integer type
 * @return If the character is between 31 and 127 it returns 1, otherwise it returns 0
 */
int		ft_isprint(int c);

/**
 * @file ft_strlen.c
 * @author oburato
 * @date 2022/04/10 15:12:22
 * @brief The function returns the length of a valid string
 * @param s representation of a string necessarily terminated with \0
 * @return the length of a string in size_t
 */
size_t	ft_strlen(const char *s);

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char	*big, const char *little, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putendl_fd(char *s, int fd);
void	ft_free(void *ptr);
void	*ft_malloc(size_t size);

void	ft_num_put_chr(char *str, long n);
size_t	ft_num_len(size_t n, size_t len);
char	*ft_unsigned_itoa(unsigned int n);

#endif