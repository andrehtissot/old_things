#ifndef _VIEWS_OPTIONS_VIEW_H_
#define _VIEWS_OPTIONS_VIEW_H_

namespace Views {
	class OptionsView : public View {
	protected:
	  OptionsView(Controller* controller, std::string const title);
	public:
	  virtual ~OptionsView();
	  virtual Window* getWindow();
	};
}

#endif