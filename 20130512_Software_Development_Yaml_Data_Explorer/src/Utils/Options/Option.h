#ifndef _UTILS_OPTIONS_OPTION_H_
#define _UTILS_OPTIONS_OPTION_H_

namespace Utils {
  namespace Options {
    class Option {
		private:
			int code;
			std::string description;
		public:
			Option();
			Option(int const code, std::string const description);
			~Option();
			const int getCode() const;
			void setCode(int const code);
			const std::string getDescription() const;
			void setDescription(std::string const description);
    };
  }
}

#endif