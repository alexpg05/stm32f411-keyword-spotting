#include <assert.h>
#include <stdio.h>
#include <tinykw_app.h>

#include "tinykw.h"
#include "keywords_encodings.h"

#define DETECTION_THRESHOLD (128)

static tkw_context tinykw_ctx;
static uint32_t keyword_ids[NB_KEYWORDS];
static tinykwCallback tinykw_callback = NULL;

/*
 * Initializes TinyKW engine and adds the keywords to it.
 */
void TinyKw_Init(tinykwCallback f)
{
	tinykw_callback = f;
	 /* Initializes TinyKW context */
	tkw_status status;
    status = tkw_init(&tinykw_ctx);
    assert(status == TKW_OK);

    /* Add the keywords to the engine */
    for (int k = 0; k < NB_KEYWORDS; ++k)
    {
        status = tkw_add_keyword(keywords_encodings[k], (uint8_t)DETECTION_THRESHOLD, &(keyword_ids[k]), &tinykw_ctx);
        assert(status == TKW_OK);
    }
}

/*
 * Process an audio frame (16-bit PCM data sampled at 16 kHz) of length TKW_AUDIO_FRAME_SIZE
 */
void TinyKw_ProcessFrame(const int16_t *audio_frame, int size)
{
	assert(size == TKW_AUDIO_FRAME_SIZE);

	/* Process the frame */
	tkw_status status;
    status = tkw_process_frame(audio_frame, size, &tinykw_ctx); // process one frame
    assert(status == TKW_OK);

    /* Check if any keyword is detected */
    for (int i = 0; i < NB_KEYWORDS; ++i)
    {
        uint32_t is_detected = 0;
        status = tkw_is_keyword_detected(keyword_ids[i], &is_detected, &tinykw_ctx); // check detection
        assert(status == TKW_OK);
        if (is_detected)
        {
            status = tkw_clear_keyword_flag(i, &tinykw_ctx); // clear flag
            assert(status == TKW_OK);
            tinykw_callback(i); // call user code
        }
    }
}
