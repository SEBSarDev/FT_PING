#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
    size_t  len;

    len = ft_strlen(s1);
	i = 0;
	while (i < len && s1[i] == s2[i] && s2[i] && s1[i])
		i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}