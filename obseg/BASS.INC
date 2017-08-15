macro align(size) { // Align Byte Amount
  while (pc() % {size}) {
    db 0
  }
}
