#pragma once
#include <windows.h>
#include <vector>
class ThreadsHandler
{
public:
	void AddThread(LPTHREAD_START_ROUTINE function, LPVOID data);
	void Wait();
	~ThreadsHandler();
private:
	std::vector<HANDLE> handles;
};

