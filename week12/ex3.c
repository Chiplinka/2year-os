#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>


static const char *const evval[3] = {
  "RELEASED", "PRESSED", "REPEATED"
};
//pe 25 + 18
//cap 46 + 30 + 25
//gg 34 + 34

int arr[3];
int i = 2;
void add(int n){
    arr[0] = arr[1];
    arr[1] = arr[2];
    arr[2] = n;
   
}

int main(void) {

  const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
  struct input_event ev;
  ssize_t n;
    int i=2;
  int fd = open(dev, O_RDONLY);

  if(fd == -1){
    fprintf(stderr, "Failed to open %s\n", dev);
    return -1;
  }

  while(1){
    read(fd, &ev, sizeof ev);
    if (ev.type == EV_KEY && ev.value == 1){
        add((int)ev.code);
        //printf("\n %d %d %d %d \n", arr[0],arr[1],arr[2]);
        //printf("%s 0x%04x (%d)\n", evval[ev.value], (int)ev.code, (int)ev.code);
         if(arr[1] == 25 && arr[2] == 18){
            printf("\n\n %s \n\n","I passed the Exam!");
        }
        if(arr[0] == 46 && arr[1] == 30 && arr[2] == 25){
            printf("\n\n %s \n\n","Get some cappuccino!");
        }
        if(arr[1] == 34 && arr[2] == KEY_L){
            printf("\n\n %s \n\n","Good luck!");
        }
    }
  }

  fflush(stdout);
  fprintf(stderr, "%s \n", strerror(errno));  
  return 0;
}