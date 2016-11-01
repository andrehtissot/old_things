#ifndef _MODELS_DAO_BINARY_DAO_BINARY_DAO_SOURCE_H_
#define _MODELS_DAO_BINARY_DAO_BINARY_DAO_SOURCE_H_
#include <string>

namespace Models {
  namespace DAO {
    namespace BinaryDAO {
      class BinaryDAOSource {
        private:
          std::string fileName;
        protected:
          BinaryDAOSource(const std::string fileName);
        public:
          virtual ~BinaryDAOSource();
        protected:
          const std::string getFileName() const;
          void setFileName(std::string const fileName);
      };
    }
  }
}

#endif