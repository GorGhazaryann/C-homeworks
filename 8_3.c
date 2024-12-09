#include <fcntl.h>
#include "8_3.h"

#define PERMISSIONS 0666

FILE _io_buffer[MAX_NR_OF_OPEN_FILES] = {
    {0, (char *)0, (char *)0, {1, 0, 0, 0, 0}, 0}, 
    {0, (char *)0, (char *)0, {0, 1, 0, 0, 0}, 1},
    {0, (char *)0, (char *)0, {0, 1, 1, 0, 0}, 2}
};

void free(void *ptr);
void *malloc(long unsigned int size);
long int lseek(int file_descriptor, long int offset, int whence);
long int read(int file_descriptor, void *buffer, long unsigned int nr_of_bytes);
long int write(int file_descriptor, void *buffer, long unsigned int nr_of_bytes);
int close(int file_descriptor);

int _fill_buffer(FILE *file_p)
{
  int buffer_size;

  if (file_p->flag._READ == 0 || file_p->flag._EOF == 1 || file_p->flag._ERR == 1)
  {
    return EOF;
  }

  buffer_size = (file_p->flag._UNBUF == 1) ? 1 : BUFFER_SIZE;

  if (file_p->base == NULL)
  {
    if ((file_p->base = (char *)malloc(buffer_size)) == NULL)
    {
      return EOF;
    }
  }

  file_p->next_char_pos_p = file_p->base;
  file_p->counter = read(file_p->file_descriptor, file_p->next_char_pos_p, buffer_size);

  if (--file_p->counter < 0)
  {
    if (file_p->counter == -1)
    {
      file_p->flag._EOF = 1;
    }
    else
    {
      file_p->flag._ERR = 1;
    }

    file_p->counter = 0;
    return EOF;
  }

  return (unsigned char)*file_p->next_char_pos_p++;
}

int _flush_buffer(int c, FILE *file_p)
{
  int buffer_size;

  if (file_p->flag._WRITE == 0 || file_p->flag._ERR == 1)
  {
    return EOF;
  }

  buffer_size = (file_p->flag._UNBUF == 1) ? 1 : BUFFER_SIZE;

  if (file_p->base == NULL)
  {
    if ((file_p->base = (char *)malloc(buffer_size)) == NULL)
    {
      return EOF;
    }
  }
  else
  {
    unsigned long nr_of_bytes = file_p->next_char_pos_p - file_p->base;
    if ((write(file_p->file_descriptor, file_p->base, nr_of_bytes)) != nr_of_bytes)
    {
      file_p->flag._ERR = 1;
      return EOF;
    }
  }

  file_p->next_char_pos_p = file_p->base;
  *file_p->next_char_pos_p++ = c;
  file_p->counter = buffer_size - 1;

  return c;
}

int file_flush(FILE *file_p)
{
  if (file_p->flag._WRITE == 0)
  {
    file_p->flag._ERR = 1;
    return EOF;
  }

  if (_flush_buffer('0', file_p) == EOF)
  {
    return EOF;
  }

  file_p->next_char_pos_p = file_p->base;
  file_p->counter = (file_p->flag._UNBUF == 1) ? 1 : BUFFER_SIZE;

  return 0;
}

FILE *file_open(char *name, char *mode)
{
  int file_descriptor;
  FILE *file_p;

  if (*mode != 'r' && *mode != 'w' && *mode != 'a')
  {
    return NULL;
  }

  for (file_p = _io_buffer; file_p < _io_buffer + MAX_NR_OF_OPEN_FILES; ++file_p)
  {
    if (file_p->flag._READ == 0 && file_p->flag._WRITE == 0)
    {
      break;
    }
  }

  if (file_p >= _io_buffer + MAX_NR_OF_OPEN_FILES)
  {
    return NULL; 
  }

  if (*mode == 'w')
  {
    file_descriptor = creat(name, PERMISSIONS);
  }
  else if (*mode == 'a')
  {
    if ((file_descriptor = open(name, O_WRONLY, 0)) == -1)
    {
      file_descriptor = creat(name, PERMISSIONS);
    }
    lseek(file_descriptor, 0L, 2);
  }
  else
  {
    file_descriptor = open(name, O_RDONLY, 0);
  }

  if (file_descriptor == -1)
  {
    return NULL;
  }

  file_p->file_descriptor = file_descriptor;
  file_p->counter = 0;
  file_p->base = NULL;
  file_p->flag._EOF = 0;
  file_p->flag._ERR = 0;
  file_p->flag._READ = (*mode == 'r') ? 1 : 0;
  file_p->flag._WRITE = (*mode == 'r') ? 0 : 1;

  return file_p;
}

int file_close(FILE *file_p)
{
  if (file_flush(file_p) == EOF)
  {
    return EOF;
  }

  free(file_p->base);
  file_p->next_char_pos_p = NULL;
  file_p->base = NULL;
  file_p->counter = 0;
  close(file_p->file_descriptor);

  return NULL;
}

int main(void)
{
  FILE *file_in_p;
  FILE *file_out_p;

  if ((file_in_p = file_open("syscalls.c", "r")) == NULL)
  {
    write(1, "Error: could not open the file.\n", 33);
    return EXIT_FAILURE;
  }

  if ((file_out_p = file_open("out.txt", "w")) == NULL)
  {
    write(1, "Error: could not open the file.\n", 33);
    return EXIT_FAILURE;
  }

  char c;
  while ((c = getc(file_in_p)) != EOF)
  {
    putc(c, file_out_p);
  }
  file_close(file_out_p);

  return EXIT_SUCCESS;
}