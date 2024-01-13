/* c_linux_threads.c - demonstrate threads in C/Linux
 * See https://github.com/fordsfords/rstone */
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
#include <unistd.h>
#include <errno.h>
#include <pthread.h>


/* print_thread object */
struct print_thread_s {
  int stats_interval_sec;
  pthread_t print_thread_id;
  int running;
};
typedef struct print_thread_s print_thread_t;


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


/* print_thread object implementation. */

void *print_thread_run(void *in_arg)
{
  print_thread_t *print_thread = (print_thread_t *)in_arg;
  int secs_since_last_print = 0;  /* Print stats immediately on start. */

  while (print_thread->running) {
    if (secs_since_last_print >= print_thread->stats_interval_sec) {
      printf("print_thread: Hi\n");
      secs_since_last_print = 0;
    }

    sleep(1);
    secs_since_last_print++;
  }  /* while running */

  printf("print_thread: bye\n");
  pthread_exit(NULL);
  return NULL;
}  /* print_thread_run */

print_thread_t *print_thread_create(int stats_interval_sec)
{
  print_thread_t *print_thread;

  ENL(print_thread = (print_thread_t *)malloc(sizeof(print_thread_t)));
  print_thread->stats_interval_sec = stats_interval_sec;
  print_thread->running = 0;
  return print_thread;
}  /* print_thread_create */

void print_thread_start(print_thread_t *print_thread)
{
  print_thread->running = 1;
  ENZ(errno = pthread_create(&print_thread->print_thread_id, NULL, print_thread_run, print_thread));
}  /* print_thread_start */

void print_thread_terminate(print_thread_t *print_thread)
{
  if (print_thread->running) {
    print_thread->running = 0;
    /* Can take up to 1 sec for stats thread to exit. */
    ENZ(errno = pthread_join(print_thread->print_thread_id, NULL));
  }
}  /* print_thread_terminate */

void print_thread_delete(print_thread_t *print_thread)
{
  if (print_thread->running) {
    print_thread_terminate(print_thread);
  }
  free(print_thread);
}  /* print_thread_delete */


int main(int argc, char **argv)
{
  print_thread_t *print_thread;

  ENL(print_thread = print_thread_create(2));
  print_thread_start(print_thread);

  printf("main:Sleeping 4.1 seconds\n");
  usleep(4100000);

  printf("terminate stats thread\n");  fflush(stdout);
  print_thread_terminate(print_thread);
  print_thread_delete(print_thread);

  return 0;
}  /* main */
