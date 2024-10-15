#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 
#define MAXLEN 1000
#define MAXSTORE 10000 

char *line_ptr[MAXLINES]; 

size_t get_line(char line[], size_t max_line_len);

int readlines(char *line_ptr[], int max_nr_of_lines, char *stored_lines);
void writelines(char *line_ptr[], int nr_of_lines);

void swap(char *v[], int i, int j);
void quick_sort(char *line_ptr[], int left, int right);

int main()
{
  int nr_of_lines;            
  char stored_lines[MAXSTORE];

  if ((nr_of_lines = readlines(line_ptr, MAXLINES, stored_lines)) >= 0)
  {
    quick_sort(line_ptr, 0, nr_of_lines - 1);
    printf("-----\n");
    writelines(line_ptr, nr_of_lines);
    return 0;
  }
  else
  {
    printf("Error: input too big to sort.\n");
    return 1;
  }
}

int readlines(char *line_ptr[], int max_nr_of_lines, char *stored_lines)
{
  int len;
  int nr_of_lines;

  char *p = stored_lines + strlen(stored_lines); 
  char line[MAXLEN];

  nr_of_lines = 0;
  while ((len = get_line(line, MAXLEN)) > 0)
  {
    if (nr_of_lines >= max_nr_of_lines || stored_lines + MAXSTORE - p < len)
    {
      return -1;
    }
    else
    {
      line[len - 1] = '\0';
      strcpy(p, line);
      line_ptr[nr_of_lines++] = p;
      p += len; 
    }
  }

  return nr_of_lines;
}

void writelines(char *line_ptr[], int nr_of_lines)
{
  while (nr_of_lines-- > 0)
  {
    printf("%s\n", *line_ptr++);
  }
}

size_t get_line(char line[], size_t max_line_len)
{
  int c;
  size_t i;

  for (i = 0; i < max_line_len - 1 && (c = getc(stdin)) != EOF && c != '\n'; ++i)
  {
    line[i] = c;
  }

  if (c == '\n')
  {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}

void quick_sort(char *v[], int left, int right)
{
  int i;
  int last;

 
  if (left >= right)
  {
    return;
  }

  swap(v, left, (left + right) / 2);
  last = left;

  for (i = left + 1; i <= right; ++i)
  {
    if (strcmp(v[i], v[left]) < 0)
    {
      swap(v, ++last, i);
    }
  }

  swap(v, left, last);
  quick_sort(v, left, last - 1);
  quick_sort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}