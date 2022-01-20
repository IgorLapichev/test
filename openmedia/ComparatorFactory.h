#pragma once

#include <memory>
#include "Comparator.h"

class ComparatorFactory
{
    enum class CompIndexes
    {
        binary = 0,
        hash
    };

public:
    std::shared_ptr<BaseComparator> getComparator(std::string&& param);

private:
    const static inline std::vector <std::pair<std::string, CompIndexes>> m_params = { {"-b", CompIndexes::binary}, {"-h", CompIndexes::hash} };
};
