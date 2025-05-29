#include "EntryPoint.h"
#include "framework/application.h"

int main() {
	//Using pointer because stack side is limited, we create large object in heap space
	ly::Application* app = GetApplication();
	app->Run();
	delete app;
}