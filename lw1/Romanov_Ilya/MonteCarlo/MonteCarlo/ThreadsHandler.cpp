#include "stdafx.h"
#include "ThreadsHandler.h"

ThreadsHandler::~ThreadsHandler() {
	for (HANDLE const& handle : handles)
	{
		CloseHandle(handle);
	}
}

void ThreadsHandler::AddThread(LPTHREAD_START_ROUTINE function, LPVOID data) {
	handles.push_back(CreateThread(NULL, NULL, function, data, NULL, NULL));
}


void ThreadsHandler::Wait() {
	if (!handles.empty()) {
		WaitForMultipleObjects(handles.size(), handles.data(), TRUE, INFINITE);
	}
}
