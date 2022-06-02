#include "push_swap.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n) {
	size_t i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	while (i < n) {
		*(char *) s1 = *(char *) s2;
		i++;
		s1++;
		s2++;
	}
	while (i > 0) {
		i--;
		s1--;
	}
	return (s1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (ft_strlen(src) + 1 < size)
		ft_memcpy(dst, src, ft_strlen(src) + 1);
	else if (size > 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (ft_strlen(src));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
