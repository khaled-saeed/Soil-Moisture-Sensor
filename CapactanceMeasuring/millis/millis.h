#ifndef _MILLIS_H_
#define _MILLIS_H_

volatile unsigned long timer1_millis;

ISR(TIMER1_COMPA_vect);
void init_millis(unsigned long f_cpu);
unsigned long millis (void);

#endif
