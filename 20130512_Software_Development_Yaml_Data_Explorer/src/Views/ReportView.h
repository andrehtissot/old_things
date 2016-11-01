#ifndef _VIEWS_REPORT_VIEW_H_
#define _VIEWS_REPORT_VIEW_H_

namespace Views {
	class ReportView : public View {
	protected:
	  ReportView(Controller* controller, std::string const title);
	public:
	  virtual ~ReportView();
	  virtual Window* getWindow();
	};
}

#endif