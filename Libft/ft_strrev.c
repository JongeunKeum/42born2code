#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char 	tmp;

	if (!str)
		return (NULL);
	i = -1;
	len = ft_strlen(str);
	while (++i < --len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
	}
	return (str);
}
