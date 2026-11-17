#ifndef INC_ILED_H_
#define INC_ILED_H_

typedef void (*LedFunction)(void);

typedef struct {
	const LedFunction On;
	const LedFunction Off;
} iLed;

#endif /* INC_ILED_H_ */
