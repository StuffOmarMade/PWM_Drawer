/*
 * WAVE_PATTERNS.h
 *
 * Created: 4/1/2024 2:21:12 PM
 *  Author: Omar
 */ 


#ifndef WAVE_PATTERNS_H_
#define WAVE_PATTERNS_H_

uint8_t rising_edge_pattern[] = {0B1000,0B1111, '\0'};
uint8_t on_pattern[] = {0B0001, '\0'};
uint8_t falling_edge_pattern[] = {0B1111,0B1000, '\0'};
uint8_t off_pattern[] = {0B1000, '\0'};

#endif /* WAVE_PATTERNS_H_ */