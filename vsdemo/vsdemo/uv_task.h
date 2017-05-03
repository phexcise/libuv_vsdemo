#pragma once
#include <uv.h>
#pragma comment(lib, "..\\libuv\\libuv.lib")
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

extern uv_loop_t *loop;

void helloworld();
void idlebasic();
void uvcat();
void filechange();
void threadcreate();
void rwlocks();
void queuework();
void queuecancel();
void progress();
