#include <string>

class InvalidInputException {
public:
    InvalidInputException(std::string reason): reason(reason) {}
    const std::string& what() { return reason; }
private:
    std::string reason = "";
};
