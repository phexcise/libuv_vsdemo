#include "stdafx.h"
#include "uv_task.h"

#define FIB_UNTIL 25
uv_work_t fib_reqs[FIB_UNTIL];

long c_fib_(long t) {
	if (t == 0 || t == 1)
		return 1;
	else
		return c_fib_(t - 1) + c_fib_(t - 2);
}

void c_fib(uv_work_t *req) {
	int n = *(int *)req->data;
	if (rand() % 2)
		Sleep(1);
	else
		Sleep(3);
	long fib = c_fib_(n);
	fprintf(stderr, "%dth fibonacci is %lu\n", n, fib);
}

void c_after_fib(uv_work_t *req, int status) {
	if (status == UV_ECANCELED)
		fprintf(stderr, "Calculation of %d cancelled.\n", *(int *)req->data);
}

void signal_handler(uv_signal_t *req, int signum)
{
	printf("Signal received!\n");
	int i;
	for (i = 0; i < FIB_UNTIL; i++) {
		uv_cancel((uv_req_t*)&fib_reqs[i]);
	}
	uv_signal_stop(req);
}

void queuecancel() {
	loop = uv_default_loop();

	int data[FIB_UNTIL];
	int i;
	for (i = 0; i < FIB_UNTIL; i++) {
		data[i] = i;
		fib_reqs[i].data = (void *)&data[i];
		uv_queue_work(loop, &fib_reqs[i], c_fib, c_after_fib);
	}

	uv_signal_t sig;
	uv_signal_init(loop, &sig);
	uv_signal_start(&sig, signal_handler, SIGINT);

	uv_run(loop, UV_RUN_DEFAULT);
}