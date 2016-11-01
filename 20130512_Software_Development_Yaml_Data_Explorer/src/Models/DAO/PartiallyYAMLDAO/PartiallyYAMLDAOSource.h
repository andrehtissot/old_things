#ifndef _MODELS_DAO_PARTIALLY_YAML_DAO_PARTIALLY_YAML_DAO_SOURCE_H_
#define _MODELS_DAO_PARTIALLY_YAML_DAO_PARTIALLY_YAML_DAO_SOURCE_H_
#include <string>
#include <vector>

namespace Models {
  namespace DAO {
    namespace PartiallyYAMLDAO {
      class PartiallyYAMLDAOSource {
        private:
          std::string fileName;
        protected:
          PartiallyYAMLDAOSource(std::string fileName);
        public:
          virtual ~PartiallyYAMLDAOSource();
          const std::string getFileName() const;
          void setFileName(std::string const fileName);
          std::vector<std::string>* findFiles();
      };
    }
  }
}

#endif