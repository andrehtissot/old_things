#ifndef _VIEWS_OPTIONS_WINDOW_H_
#define _VIEWS_OPTIONS_WINDOW_H_

namespace Views {
	class OptionsWindow : public Window {
	protected:
		OptionsWindow(View* view);
	public:
		virtual ~OptionsWindow();
	};
}

#endif