/*
** EPITECH PROJECT, 2020
** 42SH
** File description:
** Globbing-asterisk
*/

#include <glob.h>
#include <wordexp.h>
#include "minishell.h"
#include "my.h"

char *copy_new_command(int *pos, char *cmdv2, char **gl_pathv)
{
    char *temp = NULL;

    for (int i = 0; gl_pathv[i] != NULL; i++){
        temp = my_strdup(gl_pathv[i]);
        for (int j = 0; temp[j] != '\0'; j++) {
            cmdv2 = realloc(cmdv2, sizeof(char) * (*pos + 1));
            cmdv2[*pos] = temp[j];
            *pos += 1;
        }
        cmdv2 = realloc(cmdv2, sizeof(char) * (*pos + 1));
        cmdv2[*pos] = ' ';
        *pos += 1;
        free(temp);
    }
    return cmdv2;
}

char *copy_old_commands(char *newcmd, int *pos, char *cmdv2)
{
    for (int j = 0; newcmd[j] != '\0'; j++){
        cmdv2 = realloc(cmdv2, sizeof(char) * (*pos + 1));
        cmdv2[*pos] = newcmd[j];
       *pos += 1;
    }
    cmdv2 = realloc(cmdv2, sizeof(char) * (*pos + 1));
    cmdv2[*pos] = ' ';
    *pos += 1;
    return cmdv2;
}

char *get_new_command(char **newcmd, glob_t buff, int *ret)
{
    int pos = 0;
    char *cmdv2 = NULL;
    
    for (int i = 0; newcmd[i] != NULL; i++) {
        if (i == ret[1]) {
            cmdv2 = copy_new_command(&pos, cmdv2, buff.gl_pathv);
            cmdv2 = realloc(cmdv2, sizeof(char) * (pos + 1));
            cmdv2[pos] = ' ';
            pos += 1;
        }
        else
            cmdv2 = copy_old_commands(newcmd[i], &pos, cmdv2);
    }
    cmdv2 = realloc(cmdv2, sizeof(char) * (pos + 1));
    cmdv2[pos] = '\0';
    return cmdv2;
}

char *is_wildcard(char *cmd)
{
    char **newcmd = my_str_to_word_array(cmd);
    glob_t buff;
    int *ret;
    char *cmdv2 = NULL;

    ret = check_wildcard(newcmd);
    if (ret[0] != 0)
        return cmd;
    ret[0] = glob(newcmd[ret[1]], GLOB_NOCHECK, NULL, &buff);
    cmdv2 = get_new_command(newcmd, buff, ret);
    globfree(&buff);
    return cmdv2;
}
