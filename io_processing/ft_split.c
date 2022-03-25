/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:38:10 by skathale          #+#    #+#             */
/*   Updated: 2021/10/18 16:38:12 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "io_processing.h"

const static char	*ft_skip_separators(const char *str, char sep)
{
	while (*str == sep && *str != '\0')
		str++;
	return (str);
}

size_t static	ft_get_words_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		s = ft_skip_separators(s, c);
		if (*s == '\0')
			return (count);
		while (*s != c && *s != '\0')
			s++;
		count++;
	}
	return (count);
}

char static	*ft_get_new_word(char const *s, char c, size_t *word_length)
{
	char	*word;
	size_t	length;

	length = 0;
	while (s[length] != c && s[length] != '\0')
		length++;
	word = (char *) malloc(sizeof(char) * length + 1);
	if (!word)
		return (word);
	ft_strlcpy(word, s, length + 1);
	*word_length = length;
	return (word);
}

static char	**ft_free_words(char **words, size_t count)
{
	size_t	i;

	i = 0;
	while (words[i] && i < count)
		free(words[i++]);
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	words_count;
	size_t	word_length;
	size_t	word_index;

	if (!s)
		return (NULL);
	words_count = ft_get_words_count(s, c);
	words = (char **) malloc(sizeof(char *) * (words_count + 1));
	if (!words)
		return (words);
	word_length = 0;
	word_index = 0;
	s = ft_skip_separators(s, c);
	while (*s && word_index < words_count)
	{
		words[word_index] = ft_get_new_word(s, c, &word_length);
		if (!words[word_index])
			return (ft_free_words(words, words_count));
		s = s + word_length;
		s = ft_skip_separators(s, c);
		word_index++;
	}
	words[word_index] = NULL;
	return (words);
}
