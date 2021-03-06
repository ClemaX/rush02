#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>

# include "logger.h"

# define GRID_EMPTY '_'
# define GRID_PLAYER_A 'X'
# define GRID_PLAYER_B 'O'

# define TURN_PLAYER_A 1
# define TURN_PLAYER_B 2

# define BLOB_RESOLUTION 3

typedef struct
{
	char	*tab;
	int		x;
	int		y;
	int		score;
	unsigned	win_length;
	unsigned	player_turn;
	unsigned	total_time;
	unsigned	time_gain;
}		plateau;


int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		len_integer(int n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		nb_mots(char const *s, char c);
int		*nb_lettres(char const *s, char c, int nb_m);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		place(plateau *grid, int x, char player);
int		unplace(plateau *grid, int x);
int		best_move(plateau *grid, char player, unsigned blob_resolution);
int		main(void);
int		recv_pos(int *x);
int		send_pos(int x);
int		init_score_pref(char joueur2);
int		blob(plateau grille, char joueur, int coups, int n);
int		void_sniper(plateau grille, int pos, int i, int j);
int		same_sniper(plateau grille, int pos, int i, int j);
int		score_jeton(plateau grille, int pos);
int		sniper(plateau grille, int pos, int i, int j);
int		scorer(plateau grille, plateau grille2, int pos);
int		setup(plateau *grid);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	fill_tab(char const *s, char c, char **tab, int nb_m);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	print_grid(plateau *grid);
void	clear_grid(plateau *grid);
void	print_plat(plateau grille);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
plateau	init_plat(int x, int y);
plateau	clone(plateau grille);

#endif
