// Copyright 2014 Olivier Gillet.
//
// Author: Olivier Gillet (ol.gillet@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
// 
// See http://creativecommons.org/licenses/MIT/ for more information.
//
// -----------------------------------------------------------------------------
//
// Driver for the gate inputs.

#ifndef CLOUDS_DRIVERS_GATE_INPUT_H_
#define CLOUDS_DRIVERS_GATE_INPUT_H_

#include "stmlib/stmlib.h"

#include <stm32f4xx_conf.h>

namespace clouds {

class GateInput {
 public:
  GateInput() { }
  ~GateInput() { }
  
  void Init();
  void Read();
  inline bool freeze() const { return freeze_; }
  inline bool capture() const { return capture_; }
  
  inline bool freeze_rising_edge() const {
    return freeze_ && !previous_freeze_;
  }
  inline bool freeze_falling_edge() const {
    return !freeze_ && previous_freeze_;
  }
  inline bool capture_rising_edge() const {
    return capture_ && !previous_capture_;
  }
  inline bool gate() const {
    return capture_;
  }
  
 private:
  bool previous_freeze_;
  bool previous_capture_;
  bool freeze_;
  bool capture_;
  
  DISALLOW_COPY_AND_ASSIGN(GateInput);
};

}  // namespace clouds

#endif  // CLOUDS_DRIVERS_GATE_INPUT_H_
