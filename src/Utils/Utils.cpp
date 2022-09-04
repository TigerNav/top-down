#include "Utils.h"

std::string getRelativePath() {
    namespace fs = std::filesystem;
	fs::path p = fs::current_path();
    return p.parent_path().string();
}