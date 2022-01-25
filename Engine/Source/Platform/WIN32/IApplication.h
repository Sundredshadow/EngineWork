#pragma once
#include "Engine.h"

#define ENTRYAPP(x) IApplication* EntryApplication() {return new x;}

class Engine_API IApplication {
public:
	IApplication();
	virtual ~IApplication(){};

public:
	virtual void init()=0;
	virtual void update()=0;
};
IApplication* EntryApplication();