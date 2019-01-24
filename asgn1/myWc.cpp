/**********************************************
 * Last Name:   Bickner
 * First Name:  Brenden
 * Student ID:  10148167
 * Course:      CPSC 457
 * Tutorial:    1
 * Assignment:  1
 * Question:    Q4
 *
 * File name: myWc.cpp
 *********************************************/

#define _POSIX_SOURCE
#include <fcntl.h>
#include <unistd.h>
#undef _POSIX_SOURCE
#include <stdio.h>
#include <iostream>

using namespace std;

#define BUFF_SIZE 1024

int main(int argc, char * const argv[]) {
  int ret;
  char buf[BUFF_SIZE] = "";
  int count = 0;

  // get the file name from command line
  string filename;
  if (argc != 2) {
    cerr << "Usage: readFile <input file> " << endl;
    return -1;
  }
  else {
    filename = argv[1];
  }
  
  // open the file for reading
  int fd = open( filename.c_str(), O_RDONLY);
  if( fd < 0) {
    cerr << "Could not open file " << filename << "\n";
    exit(-1);
  }

  while ((ret = read(fd, buf, sizeof(buf)-1)) > 0) {
    //buf[ret] = 0x00;
    for (int i = 0; i <= sizeof(buf)-1; i++) {
      if( buf[i] == '\n') count ++;
    }
    char buf[BUFF_SIZE] = "";
  }
  
  close(fd);

  cout << count << " romeo-and-juliet.txt" << endl;
}
