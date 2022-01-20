#pragma once

#include "ComparatorFactory.h"

std::shared_ptr<BaseComparator> ComparatorFactory::getComparator(std::string&& param)
{
    auto idxIt = std::find_if(m_params.begin(), m_params.end(), [param](auto& it)
        {
            return it.first == param;
        });

    if (idxIt == m_params.end())
        throw "No such comparator";

    std::shared_ptr<BaseComparator> comparotor;
    switch (idxIt->second)
    {
    case CompIndexes::binary:
    {
        comparotor = std::make_shared <BinaryComparator>();
        break;
    }
    case CompIndexes::hash:
    {
        comparotor = std::make_shared <HashComparator>();
        break;
    }
    }

    return comparotor;
}