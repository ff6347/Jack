/**
 * Copyright 2017 Fabian Morón Zirfas
 * Permission is hereby granted, free of charge, to any
 * person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to  permit persons to
 * whom the Software is furnished to do so, subject to
 * the following conditions:
 * The above copyright notice and this permission notice
 * shall be included in all copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF  CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTIO
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * see also http://www.opensource.org/licenses/mit-license.php
 *
 * Jack in a Box Library
 * @author Fabian Morón Zirfas
 * @description A library for the "Jack in a Box" project. Using headphone jacks to communicate between Arduino boards
 */

#ifndef Jack_h
#define Jack_h

#include "Arduino.h"

class Jack {
public:
  Jack(int inpin, int outpin, boolean pullup, boolean log);
  Jack(int inpin, int outpin) : Jack(inpin, outpin, false, false){};
  Jack(int inpin, int outpin, boolean pullup) : Jack(inpin, outpin, pullup, false){};

  ~Jack();
  boolean listen();
  void send();
  void setInterval(long interval);
private:
  int _inpin;
  int _outpin;
  long _interval = 50;
  boolean _pullup = false;
  boolean _log = false;
};

#endif