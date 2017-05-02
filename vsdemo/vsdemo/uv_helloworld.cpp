#include "stdafx.h"
#include "uv_task.h"
void helloworld() {
	uv_loop_t *loop = (uv_loop_t *)malloc(sizeof(uv_loop_t));
	uv_loop_init(loop);

	printf("Now quitting.\n");
	uv_run(loop, UV_RUN_DEFAULT);

	uv_loop_close(loop);
	free(loop);
}