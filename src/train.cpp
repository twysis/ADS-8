// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  last = nullptr;
  countOp = 0;
  lenght = 0;
  a = 0;
}

void Train::addCage(bool light) {
  if (!(first)) {
    Cage* NewCage = new Cage;
    NewCage->light = light;
    NewCage->next = NewC->previous = nullptr;
    first = NewCage;
    last = first;
  } else {
    Cage* NewCage = new Cage;
    NewCage->light = light;
    NewCage->next = NewC->previous = nullptr;
    last->next = NewCage;
    last->next->previous = last;
    last = last->next;
    if (!last->next) {
      last->next = first;
    } else {
      first->previous = last;
    }
  }
}

int Train::getLength() {
  int temporary;
  first->light = true;
  last = first;
  while (true) {
    countOp++; 
    x++;
    last = last->next;
    if (last->light) {
      temporary = x;
      last->light = false;
      if ((last->previous) != nullptr) {
        while (last->light == false) {
          last = last->previous;
          x--; 
          countOp++;
        }
      }
      if (!last->light) {
        lenght = temporary;
        break;
      }
    }
  }
  countOp += lenght;
  return lenght;
}


int Train::getOpCount() {
  return countOp;
}
