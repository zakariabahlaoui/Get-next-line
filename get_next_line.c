#include "get_next_line.h"

// #define BUFFER_SIZE 10

char *ft_read_line(int fd, char *buff, char *line_save)
{
    int read_line;
    char *temp;

    read_line = 1;
    while (read_line != 0)
    {
        read_line = read(fd, buff, BUFFER_SIZE);
        if (read_line == -1)
            return 0;
        if (read_line == 0)
            break;
        buff[read_line] = '\0';
        if (!line_save)
            line_save = ft_strdup("");
        temp = line_save;
        line_save = ft_strjoin(temp, buff);
        free(temp);
        temp = NULL;
        if (ft_strchr(buff, '\n'))
            break;
    }
    return line_save;
}

char *ft_get_line(char *save)
{
    int i;
    char *s;

    i = 0;
    if (!save[i])
        return NULL;
    while (save[i] != '\n' && save[i])
        i++;
    // if (save[i + 1] == '\n')
    s = (char *)malloc(sizeof(char) * i + 2);
    // if (save[i + 1] == '\0')
    //     s = (char *)malloc(sizeof(char) * i + 1);
    if (!s)
        return NULL;
    i = 0;
    while (save[i] && save[i] != '\n')
    {
        s[i] = save[i];
        i++;
    }
    if (save[i] == '\n')
    {
        s[i] = save[i];
        i++;
    }
    s[i] = '\0';
    return s;
}

char *ft_save_line(char *line)
{
    int i;
    int j;
    char *s;
    int c;

    i = 0;
    while (line[i] != '\n' && line[i] != '\0')
        i++;
    if (line[i] == '\0')
        return 0;
    c = i + 1;

    s = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
    if (!s)
        return (NULL);
    i++;
    j = 0;
    while (line[i])
    {
        s[j] = line[i];
        j++;
        i++;
    }
    s[j] = '\0';
    if (s[0] == '\0')
    {
        free(s);
        s = NULL;
    }
    line[c] = 0;
    return s;
}

char *get_next_line(int fd)
{
    char *line;
    static char *line_save;
    char *buff;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return 0;
    buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return 0;

    line = ft_read_line(fd, buff, line_save);
    free(buff);
    buff = NULL;

    // line = ft_get_line(line_save);
    if (!line)
        return NULL;
    // if (line[0] == '\n')
    //     return NULL;

    line_save = ft_save_line(line);

    return line;
}

// int main()
// {
//     int fd = 0;
//     char *txt;
//     int i;

//     fd = open("text.txt", O_RDONLY);

//     i = 0;
//     while (i < 6)
//     {
//         txt = get_next_line(fd);
//         // if (txt == NULL)
//         //     break;
//         printf("%s", txt);
//         free(txt);
//         i++;
//     }

//     return 0;
// }
