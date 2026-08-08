#ifndef INC_LIGHTS_H_
#define INC_LIGHTS_H_

typedef enum {OFF, YELLOW, RED, GREEN, BLINK_SLOW, BLINK_FAST, CONTINUOUS} LightState;

void update_lights(LightState input_state);

#endif /* INC_LIGHTS_H_ */
