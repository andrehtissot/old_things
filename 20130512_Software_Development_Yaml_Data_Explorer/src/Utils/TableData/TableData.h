#ifndef _UTILS_TABLE_DATA_TABLE_DATA_H_
#define _UTILS_TABLE_DATA_TABLE_DATA_H_

namespace Utils {
	namespace TableData {
		class TableData {
			private:
				std::string description;
				float value;
			public:
				TableData();
				TableData(int const value, std::string const description);
				~TableData();
				const std::string getDescription() const;
				void setDescription(std::string const description);
				const float getValue() const;
				void setValue(float const value);
		};
	}
}

#endif