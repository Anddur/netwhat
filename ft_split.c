#include <unistd.h>
#include <stdlib.h>

size_t		ft_strlen(const char *s)
{
	size_t size;

	size = 0;
	while (s[size] != 0)
		size++;
	return (size);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t index;

	index = 0;
	if (dstsize == 0)
	{
		while (src[index])
			index++;
		return (index);
	}
	while (index < dstsize - 1 && src[index] != 0)
	{
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		index++;
	}
	dst[index] = '\0';
	return (ft_strlen(src));
}

static unsigned int		count_word(char const *s, char c)
{
	unsigned int	index;
	unsigned int	num_word;

	if (!s[0])
		return (0);
	index = 0;
	num_word = 0;
	while (s[index] && s[index] == c)
		index++;
	while (s[index])
	{
		if (s[index] == c)
		{
			num_word++;
			while (s[index] && s[index] == c)
				index++;
			continue ;
		}
		index++;
	}
	if (s[index - 1] != c)
		num_word++;
	return (num_word);
}

static void				next_word(char **word, unsigned int *word_len, char c)
{
	unsigned int	index;

	*word += *word_len;
	*word_len = 0;
	index = 0;
	while (**word && **word == c)
		(*word)++;
	while ((*word)[index])
	{
		if ((*word)[index] == c)
			return ;
		(*word_len)++;
		index++;
	}
}

char					**ft_split(char const *s, char c)
{
	char			**split;
	char			*word;
	unsigned int	word_len;
	unsigned int	num_word;
	unsigned int	index;

	if (s == NULL)
		return (NULL);
	num_word = count_word(s, c);
	if (!(split = (char **)malloc(sizeof(char *) * (num_word + 1))))
		return (NULL);
	index = 0;
	word = (char *)s;
	word_len = 0;
	while (index < num_word)
	{
		next_word(&word, &word_len, c);
		if (!(split[index] = (char *)malloc(sizeof(char) * (word_len + 1))))
			return (NULL);
		ft_strlcpy(split[index], word, word_len + 1);
		index++;
	}
	split[index] = NULL;
	return (split);
}
