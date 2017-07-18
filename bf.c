/*
 * bf.c
 * 
 * Copyright 2017 nimalan <nimalan@mark>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#include<stdio.h>
int main(int argc, char**argv) {
  char m[30000] = {0}, c;
  int l[100],i=0,k=-1,p;
  FILE* f;
  f = fopen(argv[1], "r");
  while(++i,c=getc(f),c!=EOF) {
    switch(c) {
      case '>':
        p++;
        break;
      case '<':
        if(p>0)p--;
        break;
      case '+':
        m[p]=(m[p]+1)%256;
        break;
      case '-':
        m[p]=(m[p]-1)%256;
        break;
      case '.':
        putchar(m[p]);
        break;
      case ',':
        m[p] = getchar();
        break;
      case '[':
        if(!m[p]) {
          while(++i,c=getc(f),c!=EOF&&c!=']');
          if(c!=EOF)c=getc(f);
        }
        else
          l[++k]=i-1;
        break;
      case ']':
        if(m[p]) {
          i = l[k--];
          fseek(f, i, SEEK_SET);
        }
    }
  }
  return 0;
}
