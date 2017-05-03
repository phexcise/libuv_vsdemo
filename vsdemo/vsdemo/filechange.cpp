#include "stdafx.h"
#include "uv_task.h"

const char *command;

void run_command(uv_fs_event_t *handle, const char *filename, int events, int status) {
	char path[1024];
	size_t size = 1023;
	// Does not handle error if path is longer than 1023.
	uv_fs_event_getpath(handle, path, &size);
	path[size] = '\0';

	fprintf(stderr, "Change detected in %s: ", path);
	if (events & UV_RENAME)
		fprintf(stderr, "renamed");
	if (events & UV_CHANGE)
		fprintf(stderr, "changed");

	fprintf(stderr, " %s\n", filename ? filename : "");
	system(command);
}

void filechange() {
	char* strFilePath = "..\\test\\filechange.txt";

	loop = uv_default_loop();

	fprintf(stderr, "Adding watch on %s\n", strFilePath);
	uv_fs_event_t *fs_event_req = (uv_fs_event_t *)malloc(sizeof(uv_fs_event_t));
	uv_fs_event_init(loop, fs_event_req);
	// The recursive flag watches subdirectories too.
	uv_fs_event_start(fs_event_req, run_command, strFilePath, UV_FS_EVENT_RECURSIVE);

	uv_run(loop, UV_RUN_DEFAULT);
}