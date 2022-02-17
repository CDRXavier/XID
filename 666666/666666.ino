/*
Buttons example
June 11, 2015
Copyright (C) 2015 David Martinez
All rights reserved.
This code is the most basic barebones code for showing how to use buttons in
Arduboy.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
*/

//#include <Arduboy2.h>

// Make an instance of arduboy used for many functions
//Arduboy2 arduboy;

// Variables for your game go here.
//char title[] = "Press Buttons!";
//byte x;
//byte y;

// Width of each charcter including inter-character space
//#define CHAR_WIDTH 6

// Height of each charater
//#define CHAR_HEIGHT 8

// To get the number of characters, we subtract 1 from the length of
// the array because there will be a NULL terminator at the end.
//#define NUM_CHARS (sizeof(title) - 1)

// This is the highest value that x can be without the end of the text
// going farther than the right side of the screen. We add one because
// there will be a 1 pixel space at the end of the last character.
// WIDTH and HEIGHT are defined in the Arduboy library.
//#define X_MAX (WIDTH - (NUM_CHARS * CHAR_WIDTH) + 1)

// This is the highest value that y can be without the text going below
// the bottom of the screen.
//#define Y_MAX (HEIGHT - CHAR_HEIGHT)

//#define ENCODER_DO_NOT_USE_INTERRUPTS
//we have interuupt on all pins on PortB and PD0123
#include "Encoder.h"

uint_fast8_t poiuytr;

Encoder EncX(11, 10);
Encoder EncY(9, 8);
Encoder EncZ(0, 1);
//Encoder EncXz(2, 3);

//ThumbPointer for Rx and Ry

// This function runs once in your game.
// use it for anything that needs to be set only once in your game.
void setup() {
  //initiate arduboy instance
//  arduboy.begin();
Serial.begin(9600);

// here we set the framerate to 30, we do not need to run at default 60 and
  // it saves us battery life.
//  arduboy.setFrameRate(30);

  // set x and y to the middle of the screen
//  x = (WIDTH / 2) - (NUM_CHARS * CHAR_WIDTH / 2);
//  y = (HEIGHT / 2) - (CHAR_HEIGHT / 2);
}
short posX = 0;
short posY = 0;
short nPosY = 0;
short nPosX = 0;
// our main game loop, this runs once every cycle/frame.
// this is where our game logic goes.
void loop() {
  nPosX = EncX.read();
  nPosY = EncY.read();
  if (posX != nPosX) {
    posX = nPosX;
    Serial.println(nPosX);
  }

  if (nPosY != posY) {
    posY = nPosY;
    Serial.println(nPosY);
  }
  delay(5);
}
