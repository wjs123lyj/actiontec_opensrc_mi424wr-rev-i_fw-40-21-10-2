/* DO NOT EDIT THIS FILE - it is machine generated */
#include <native.h>

#ifndef _Included_java_lang_VMThread
#define _Included_java_lang_VMThread

#ifdef __cplusplus
extern "C" {
#endif

/* Header for class java_lang_VMThread */

typedef struct Hjava_lang_VMThread {
  /* Fields from java/lang/Object: */
  Hjava_lang_Object base;

  /* Fields from java/lang/VMThread: */
  struct Hjava_lang_Thread* thread;
  jboolean running;
  struct Hkaffe_util_Ptr* vmdata;
} Hjava_lang_VMThread;

extern jint java_lang_VMThread_countStackFrames(struct Hjava_lang_VMThread*);
extern void java_lang_VMThread_start(struct Hjava_lang_VMThread*, jlong);
extern void java_lang_VMThread_interrupt(struct Hjava_lang_VMThread*);
extern jboolean java_lang_VMThread_isInterrupted(struct Hjava_lang_VMThread*);
extern void java_lang_VMThread_nativeSetPriority(struct Hjava_lang_VMThread*, jint);
extern struct Hjava_lang_Thread* java_lang_VMThread_currentThread(void);
extern void java_lang_VMThread_yield(void);
extern jboolean java_lang_VMThread_interrupted(void);
extern void java_lang_VMThread_finalize(struct Hjava_lang_VMThread*);

#ifdef __cplusplus
}
#endif

#endif