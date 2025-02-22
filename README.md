# get_next_line

char	*ft_strdup(const char *src, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (NULL);
	while (i < size + 1)
	{
		ptr[i] = src[i];
		i++;
	}
	return (ptr);
}