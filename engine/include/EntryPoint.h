#pragma once

namespace ly {
	/*
		Because the GetApplication declared outside the namespace, and this translation unit cannot view the Application object here,
		so that we need forward declaration
	 */
	class Application;
	
}

/*
	The extern keyword means that this function implemented somewhere but not here, actually it is function not a class implementation.
	The responsibility for implement the GetApplication function let to the other application.
*/
extern ly::Application* GetApplication();