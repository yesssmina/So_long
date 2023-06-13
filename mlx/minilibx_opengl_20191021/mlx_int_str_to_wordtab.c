//
// str 2 wordtab & co
// by ol


#include <stdlib.h>
#include <string.h>

int	mlx_int_str_str(char *str,char *find,int len)
{
  int	len_f;
  int	point;
  char	*s;
  char	*f;

  len_f = strlen(find);
  if (len_f>len)
    return (-1);
  point = 0;
  while (*(str+len_f-1))
    {
      s = str;
      f = find;
      while (*(f++) == *(s++))
        if (!*f)
          return (point);
      str ++;
      point ++;
    }
  return (-1);
}



int	mlx_int_str_str_cote(char *str,char *find,int len)
{
  int	len_f;
  int	point;
  char	*s;
  char	*f;
  int	cote;

  len_f = strlen(find);
  if (len_f>len)
    return (-1);
  cote = 0;
  point = 0;
  while (*(str+len_f-1))
    {
      if (*str=='"')
	cote = 1-cote;
      if (!cote)
	{
	  s = str;
	  f = find;
	  while (*(f++) == *(s++))
	    if (!*f)
	      return (point);
	}
      str ++;
      point ++;
    }
  return (-1);
}


char	**mlx_int_str_to_wordtab(char *str)
{
  char	**tab;
  int	point;
  int	nb_word;
  int	len;

  len = strlen(str);
  nb_word = 0;
  point = 0;
  while (point<len)
  {
    while (*(str+point)==' ' || *(str+point)=='\t')
      point ++;
    if (*(str+point))
      nb_word ++;
    while (*(str+point) && *(str+point)!=' ' && *(str+point)!='\t')
      point ++;
  }
  if (!(tab = malloc((1+nb_word)*sizeof(*tab))))
    return ((char **)0);
  nb_word = 0;
  point = 0;
  while (point<len)
    {
      while (*(str+point)==' ' || *(str+point)=='\t')
	{
	  *(str+point) = 0;
	  point ++;
	}
      if (*(str+point))
	{
	  tab[nb_word] = str+point;
	  nb_word ++;
	}
      while (*(str+point) && *(str+point)!=' ' && *(str+point)!='\t')
	point ++;
    }
  tab[nb_word] = 0;
  return (tab);
}
