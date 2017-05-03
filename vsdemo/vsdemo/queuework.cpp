#include "stdafx.h"
#include "uv_task.h"

#define FIB_UNTIL 25

long fib_(long t) {
	if (t == 0 || t == 1)
		return 1;
	else
		return fib_(t - 1) + fib_(t - 2);
}

void fib(uv_work_t *req) {
	int n = *(int *)req->data;
	if (rand() % 2)
		Sleep(1);
	else
		Sleep(3);
	long fib = fib_(n);
	fprintf(stderr, "%dth fibonacci is %lu\n", n, fib);
}

void after_fib(uv_work_t *req, int status) {
	fprintf(stderr, "Done calculating %dth fibonacci\n", *(int *)req->data);
}

void queuework() {
	loop = uv_default_loop();

	int data[FIB_UNTIL];
	uv_work_t req[FIB_UNTIL];
	int i;
	for (i = 0; i < FIB_UNTIL; i++) {
		data[i] = i;
		req[i].data = (void *)&data[i];
		uv_queue_work(loop, &req[i], fib, after_fib);
	}

	uv_run(loop, UV_RUN_DEFAULT);
}