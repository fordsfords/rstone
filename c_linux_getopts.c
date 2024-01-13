/* c_linux_getopts.c - demonstrate command-ine parsing in C/Linux
 * See https://github.com/fordsfords/rstone
 */
/*
# This code and its documentation is Copyright 2023,2024 Steven Ford
# and licensed "public domain" style under Creative Commons "CC0":
#   http://creativecommons.org/publicdomain/zero/1.0/
# To the extent possible under law, the contributors to this project have
# waived all copyright and related or neighboring rights to this work.
# In other words, you can use this code for any purpose without any
# restrictions.  This work is published from: United States.  The project home
# is https://github.com/fordsfords/rstone
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <unistd.h>


struct cmd_line_s {
  int test_num;      /* -t option. */
  char *input_file;  /* positional parameter. */
};
typedef struct cmd_line_s cmd_line_t;


/* Error if non-zero. */
#define ENZ(enz_sys_call_) do { \
  int enz_ = (enz_sys_call_); \
  if (enz_ != 0) { \
    int enz_errno_ = errno; \
    char enz_errstr_[1024]; \
    sprintf(enz_errstr_, "ERROR (%s:%d): %s failed", __FILE__, __LINE__, #enz_sys_call_); \
    errno = enz_errno_; \
    perror(enz_errstr_); \
    exit(1); \
  } \
} while (0)  /* ENZ */

/* Error if NULL. */
#define ENL(enl_sys_call_) do { \
  void *enl_ = (enl_sys_call_); \
  if (enl_ == NULL) { \
    int enl_errno_ = errno; \
    char enl_errstr_[1024]; \
    sprintf(enl_errstr_, "ERROR (%s:%d): %s failed", __FILE__, __LINE__, #enl_sys_call_); \
    errno = enl_errno_; \
    perror(enl_errstr_); \
    exit(1); \
  } \
} while (0)  /* ENL */


void cmd_line_usage(char *err_msg)
{
  if (err_msg != NULL) {
    fprintf(stderr, "Error: %s\n", err_msg);
  }
  fprintf(stderr, "Usage: c_linux_getopts [-h] [-t testnum] input_file\n");
  exit(1);
}  /* cmd_line_usage */

void cmd_line_help()
{
  printf("Usage: c_linux_getopts [-h] [-t testnum] input_file\n"
         "Where:\n"
         "  -h : help (prints this help text)\n"
         "  -t testnum : number of test to perform\n"
         "  input_file : required positional parameter\n"
  );
  exit(0);
}  /* cmd_line_help */

cmd_line_t *cmd_line_create(int argc, char **argv)
{
  int opt;

  cmd_line_t *cmd_line;
  ENL(cmd_line = (cmd_line_t *)malloc(sizeof(cmd_line_t)));

  /* Set defaults. */
  cmd_line->test_num = 1;
  cmd_line->input_file = strdup("");  /* zero-length: no file. */

  while ((opt = getopt(argc, argv, "ht:")) != EOF) {
    switch (opt) {
      case 't':
        cmd_line->test_num = atoi(optarg);
        break;
      case 'h':
        cmd_line_help();
        break;
      default:
        cmd_line_usage(NULL);
    }  /* switch opt */
  }  /* while getopt */

  if (optind == argc) {
    cmd_line_usage("Missing inputfile");
  }
  else {
    free(cmd_line->input_file);
    cmd_line->input_file = strdup(argv[optind]);
    optind++;
  }
  if (optind != argc) { cmd_line_usage("Extra parameter(s)"); }

  return cmd_line;
}  /* cmd_line_create */

void cmd_line_delete(cmd_line_t *cmd_line)
{
  free(cmd_line->input_file);
  free(cmd_line);
}  /* cmd_line_delete */


int main(int argc, char **argv)
{
  cmd_line_t *cmd_line;

  ENL(cmd_line = cmd_line_create(argc, argv));

  printf("test_num=%d, input_file='%s'\n",
    cmd_line->test_num, cmd_line->input_file);

  cmd_line_delete(cmd_line);

  return 0;
}  /* main */
