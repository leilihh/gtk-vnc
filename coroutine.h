#ifndef _COROUTINE_H_
#define _COROUTINE_H_

#include "continuation.h"

struct coroutine
{
	size_t stack_size;
	void *(*entry)(void *);
	int (*release)(struct coroutine *);

	/* read-only */
	int exited;

	/* private */
	struct coroutine *caller;
	void *data;

	struct continuation cc;
};

int coroutine_init(struct coroutine *co);

int coroutine_release(struct coroutine *co);

void *coroutine_swap(struct coroutine *from, struct coroutine *to, void *arg);

struct coroutine *coroutine_self(void);

void *yieldto(struct coroutine *to, void *arg);

void *yield(void *arg);

#endif
