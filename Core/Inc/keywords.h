#ifndef INC_KEYWORDS_H_
#define INC_KEYWORDS_H_

#define NB_KEYWORDS (7)

void TinyKw_Init(void);
int TinyKw_ProcessFrame(const int16_t *audio_frame, int size);

#endif
