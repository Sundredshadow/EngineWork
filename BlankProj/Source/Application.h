#pragma once
#include "pch.h"
#include "Entry.h"

class Application : public IApplication {
public:
	Application();
	~Application();

private:
	void init();
	void update();
};