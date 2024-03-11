/*
 * This file is part of the Arducam SPI Camera project.
 *
 * Copyright 2021 Arducam Technology co., Ltd. All Rights Reserved.
 *
 * This work is licensed under the MIT license, see the file LICENSE for
 * details.
 *
 */
#include "Arducam.h"
#include "Platform.h"
#include <stdio.h>
#include <termio.h>
#include <unistd.h>

int key = 0;
int csPin = 8;
ArducamCamera myCAM;
int count = 0;
char name[10] = {0};
unsigned char imageBuff[0xFF] = {0};
unsigned int imageLength = 0;
int scanKeyboard() {
  int in;
  struct termios new_settings;
  struct termios stored_settings;
  tcgetattr(0, &stored_settings);
  new_settings = stored_settings;
  new_settings.c_lflag &= (~ICANON);
  new_settings.c_cc[VTIME] = 0;
  tcgetattr(0, &stored_settings);
  new_settings.c_cc[VMIN] = 1;
  tcsetattr(0, TCSANOW, &new_settings);

  in = getchar();

  tcsetattr(0, TCSANOW, &stored_settings);
  return in;
}

void saveImage(ArducamCamera myCAM) {
  unsigned long value = 0;
  unsigned char data = 0;
  FILE *fl = NULL;
  sprintf(name, "%d.jpg", count);
  fl = fopen(name, "w+");
  if (fl == NULL) {
    printf("Create file failed\r\n");
    return;
  }
  while (myCAM.receivedLength) {
    imageLength = readBuff(&myCAM, imageBuff, 0xFF);
    fwrite(imageBuff, 1, imageLength, fl);
  }

  fclose(fl);
  count++;
}

#define MS_TO_US(ms) (ms * 1000)

int main(void) {
  printf("Initializing the camera\n");
  unsigned char sendBuff[10] = {0};
  unsigned char readBuff[10] = {0};
  myCAM = createArducamCamera(csPin);
  begin(&myCAM);

  // Initialize auto focus
  setAutoFocus(&myCAM, 0);

  setImageQuality(&myCAM, HIGH_QUALITY);

  lowPowerOn(&myCAM);

  printf("Camera Init Succeed\r\n");
  printf("Click the 's' button on the keyboard to save the image and 'f' to "
         "trigger focus\r\n");
  printf("Press the keyboard 'q' key to exit\r\n");
  int count = 0;

  while (1) {
    key = scanKeyboard();
    if (key == 's') //'s'
    {
      lowPowerOff(&myCAM);

      setAutoFocus(&myCAM, 1);

      // Give it time to focus
      usleep(MS_TO_US(2000));

      takePicture(&myCAM, CAM_IMAGE_MODE_WQXGA2, CAM_IMAGE_PIX_FMT_JPG);
      lowPowerOn(&myCAM);

      saveImage(myCAM);
      printf("Image save succeed\r\n");
    } else if (key == 'q') {
      printf("\r\n");
      printf("quit picture mode\r\n");
      break;
    } else if (key == 'f') {
      printf("Focusing\n");
      setAutoFocus(&myCAM, 1);
    }
  }
  spiRelease();
  return 0;
}
