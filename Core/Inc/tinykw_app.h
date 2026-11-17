#ifndef INC_TINYKW_APP_H_
#define INC_TINYKW_APP_H_

#include <stdint.h>

typedef void (*tinykwCallback)(uint32_t idx_keyword); // idx_keyword follows the order of added keywords
void TinyKw_Init(tinykwCallback f);
void TinyKw_ProcessFrame(const int16_t *audio_frame, int size);

#endif
